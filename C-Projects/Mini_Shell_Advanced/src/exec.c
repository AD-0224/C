#include "shell.h"

extern char **environ;
char *find_path(char *cmd)
{
    char *path_env;
    char *path_copy;
    char *dir;
    char *full_path;

    if (strchr(cmd, '/'))
        return (strdup(cmd));
    path_env = getenv("PATH");
    if (!path_env)
        return (NULL);
    path_copy = strdup(path_env);
    if (!path_copy)
        return (NULL);
    dir = strtok(path_copy, ":");
    while (dir)
    {
        full_path = malloc(strlen(dir) + strlen(cmd) + 2);
        if (!full_path)
        {
            free(path_copy);
            return (NULL);
        }
        sprintf(full_path, "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }
        free(full_path);
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return (NULL);
}

void apply_redirections(t_cmd *cmd)
{
    int fd;

    if (cmd->heredoc)
    {
        fd = open(cmd->heredoc, O_RDONLY);
        if (fd == -1)
        {
            perror(cmd->heredoc);
            exit(1);
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
        unlink(cmd->heredoc);
    }
    else if (cmd->infile)
    {
        fd = open(cmd->infile, O_RDONLY);
        if (fd == -1)
        {
            perror(cmd->infile);
            exit(1);
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    if (cmd->outfile)
    {
        if (cmd->append)
            fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
        else
            fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1)
        {
            perror(cmd->outfile);
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }
}

static void exec_external(t_cmd *cmd)
{
    char *path;

    path = find_path(cmd->argv[0]);
    if (!path)
    {
        fprintf(stderr, "%s: command not found\n", cmd->argv[0]);
        exit(127);
    }
    execve(path, cmd->argv, environ);
    perror("execve");
    exit(126);
}

// Une seule commande, sans pipe : on ne fork que si necessaire.
// cd/export/unset/exit doivent tourner DANS le shell parent pour avoir un effet.
static void run_single(t_cmd *cmd)
{
    pid_t pid;
    int status;

    if (!cmd->argv[0])
        return;
    if (is_builtin(cmd->argv[0]) && !cmd->infile && !cmd->outfile && !cmd->heredoc)
    {
        g_exit_status = exec_builtin(cmd);
        return;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return;
    }
    if (pid == 0)
    {
        setup_signals_child();
        apply_redirections(cmd);
        if (is_builtin(cmd->argv[0]))
            exit(exec_builtin(cmd));
        exec_external(cmd);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        g_exit_status = WEXITSTATUS(status);
    else if (WIFSIGNALED(status))
        g_exit_status = 128 + WTERMSIG(status);
}

static int count_cmds(t_cmd *cmds)
{
    int n;

    n = 0;
    while (cmds)
    {
        n++;
        cmds = cmds->next;
    }
    return (n);
}

// Plusieurs commandes reliees par des pipes : on cree n-1 pipes,
// on fork n enfants, chacun se branche sur le pipe precedent/suivant.
static void run_pipeline(t_cmd *cmds)
{
    int n;
    int i;
    int (*pipes)[2];
    pid_t *pids;
    t_cmd *tmp;
    int status;

    n = count_cmds(cmds);
    pipes = malloc(sizeof(int[2]) * (n - 1 > 0 ? n - 1 : 1));
    pids = malloc(sizeof(pid_t) * n);
    i = 0;
    while (i < n - 1)
    {
        if (pipe(pipes[i]) == -1)
        {
            perror("pipe");
            return;
        }
        i++;
    }
    tmp = cmds;
    i = 0;
    while (tmp)
    {
        pids[i] = fork();
        if (pids[i] == 0)
        {
            setup_signals_child();
            if (i > 0)
                dup2(pipes[i - 1][0], STDIN_FILENO);
            if (i < n - 1)
                dup2(pipes[i][1], STDOUT_FILENO);
            int k = 0;
            while (k < n - 1)
            {
                close(pipes[k][0]);
                close(pipes[k][1]);
                k++;
            }
            apply_redirections(tmp);
            if (is_builtin(tmp->argv[0]))
                exit(exec_builtin(tmp));
            exec_external(tmp);
        }
        tmp = tmp->next;
        i++;
    }
    i = 0;
    while (i < n - 1)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        waitpid(pids[i], &status, 0);
        if (i == n - 1)
        {
            if (WIFEXITED(status))
                g_exit_status = WEXITSTATUS(status);
            else if (WIFSIGNALED(status))
                g_exit_status = 128 + WTERMSIG(status);
        }
        i++;
    }
    free(pipes);
    free(pids);
}

void execute_pipeline(t_cmd *cmds)
{
    if (!cmds || !cmds->argv || !cmds->argv[0])
        return;
    if (handle_heredocs(cmds) == -1)
        return;
    if (!cmds->next)
        run_single(cmds);
    else
        run_pipeline(cmds);
}