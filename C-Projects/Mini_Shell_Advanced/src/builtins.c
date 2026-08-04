#include "shell.h"

extern char **environ;

int is_builtin(char *cmd)
{
    if (!cmd)
        return (0);
    return (!strcmp(cmd, "cd") || !strcmp(cmd, "echo") || !strcmp(cmd, "pwd")
        || !strcmp(cmd, "exit") || !strcmp(cmd, "export")
        || !strcmp(cmd, "unset") || !strcmp(cmd, "env"));
}

static int bi_cd(char **argv)
{
    char *target;

    target = argv[1];
    if (!target)
    {
        target = getenv("HOME");
        if (!target)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return (1);
        }
    }
    if (chdir(target) != 0)
    {
        perror("cd");
        return (1);
    }
    return (0);
}

static int bi_echo(char **argv)
{
    int i;
    int newline;

    i = 1;
    newline = 1;
    if (argv[i] && !strcmp(argv[i], "-n")) //-n mean no /n after don't forget it 
    {
        newline = 0;
        i++;
    }
    while (argv[i])
    {
        printf("%s", argv[i]);
        if (argv[i + 1])
            printf(" ");
        i++;
    }
    if (newline)
        printf("\n");
    return (0);
}

static int bi_pwd(void)
{
    char cwd[4096];

    if (!getcwd(cwd, sizeof(cwd)))
    {
        perror("pwd");
        return (1);
    }
    printf("%s\n", cwd);
    return (0);
}

static int bi_export(char **argv)
{
    int i;
    char *eq;

    i = 1;
    while (argv[i])
    {
        eq = strchr(argv[i], '=');
        if (eq)
        {
            *eq = '\0';
            setenv(argv[i], eq + 1, 1);
            *eq = '=';
        }
        i++;
    }
    return (0);
}

static int bi_unset(char **argv)
{
    int i;

    i = 1;
    while (argv[i])
    {
        unsetenv(argv[i]);
        i++;
    }
    return (0);
}

static int bi_env(void)
{
    int i;

    i = 0;
    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
    return (0);
}

int exec_builtin(t_cmd *cmd)
{
    char *name;

    name = cmd->argv[0];
    if (!strcmp(name, "cd"))
        return (bi_cd(cmd->argv));
    if (!strcmp(name, "echo"))
        return (bi_echo(cmd->argv));
    if (!strcmp(name, "pwd"))
        return (bi_pwd());
    if (!strcmp(name, "export"))
        return (bi_export(cmd->argv));
    if (!strcmp(name, "unset"))
        return (bi_unset(cmd->argv));
    if (!strcmp(name, "env"))
        return (bi_env());
    if (!strcmp(name, "exit"))
    {
        printf("exit\n");
        exit(cmd->argv[1] ? atoi(cmd->argv[1]) : g_exit_status);
    }
    return (1);
}