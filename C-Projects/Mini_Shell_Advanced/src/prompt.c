#include "shell.h"

char *build_prompt(void)
{
    char cwd[4096];
    char *prompt;

    if (!getcwd(cwd, sizeof(cwd)))
        strcpy(cwd, "?");
    prompt = malloc(strlen(cwd) + 64);
    if (!prompt)
        return (strdup("$ "));
    sprintf(prompt, "\001\033[1;32m\002minishell\001\033[0m\002:\001\033[1;34m\002%s\001\033[0m\002$ ",cwd); 
    return (prompt);
}