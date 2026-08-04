#include "shell.h"
#include <readline/readline.h>
#include <readline/history.h>

void shell_loop(void)
{
    char *line;
    char *prompt;

    while (1)
    {
        prompt = build_prompt();
        line = readline(prompt);
        free(prompt);

        if (!line)
        {
            printf("exit\n");
            break;
        }
        if (*line)
            add_history(line);

        if (!strcmp(line, "exit"))
        {
            free(line);
            break;
        }
        execute_command(line);
        free(line);
    }
}