#include "shell.h"

static char *make_tmp_path(void)
{
    static int counter = 0;
    char *path;

    path = malloc(64);
    if (!path)
        return (NULL);
    sprintf(path, "/tmp/.mshell_heredoc_%d_%d", getpid(), counter++);
    return (path);
}

static int fill_heredoc_file(char *delim, char *path)
{
    int fd;
    char *line;
    size_t cap;
    ssize_t r;

    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);
    line = NULL;
    cap = 0;
    while (1)
    {
        printf("> ");
        fflush(stdout);
        errno = 0;
        r = getline(&line, &cap, stdin);
        if (g_heredoc_interrupted)
        {
            printf("\n");
            free(line);
            close(fd);
            return (-1);
        }
        if (r == -1)
        {
            if (errno == EINTR)
            {
                clearerr(stdin);
                continue;
            }
            break;
        }
        line[strcspn(line, "\r\n")] = 0;
        if (!strcmp(line, delim))
            break;
        write(fd, line, strlen(line));
        write(fd, "\n", 1);
    }
    free(line);
    close(fd);
    return (0);
}

int handle_heredocs(t_cmd *cmds)
{
    char *path;

    while (cmds)
    {
        if (cmds->heredoc)
        {
            g_heredoc_interrupted = 0;
            setup_signals_heredoc();
            path = make_tmp_path();
            if (!path)
            {
                setup_signals_parent();
                return (-1);
            }
            if (fill_heredoc_file(cmds->heredoc, path) == -1)
            {
                setup_signals_parent();
                unlink(path);
                free(path);
                return (-1);
            }
            setup_signals_parent();
            free(cmds->heredoc);
            cmds->heredoc = path;
        }
        cmds = cmds->next;
    }
    return (0);
}