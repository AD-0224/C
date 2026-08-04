#include "shell.h"

char **split_simple(char *line)
{
    char **args = malloc(sizeof(char *) * 64);
    int i = 0;

    char *token = strtok(line, " ");
    while (token)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

void execute_command(char *line)
{
    t_token *tokens;
    t_cmd *cmd;

    tokens = lexer(line);
    cmd = parseur(tokens);
    free_tokens(tokens);

    if (cmd)
    {
        expand_cmd(cmd);
        execute_pipeline(cmd);
    }
    free_cmd(cmd);
}