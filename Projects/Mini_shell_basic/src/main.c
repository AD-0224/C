#include "MINI_SHELL_BASIC.h"

int main ()
{
    char input[1024];
    char *args[MAX_ARGS];
    while (1)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("[%s] minishell$ ", cwd);

        if (fgets(input, sizeof(input), stdin) == NULL) //secure reading
        {
            printf("\nGoodbye !\n");
            break;
        }
        
        char **parsed_args = parse_input(input, args);

        if (parsed_args[0] == NULL)
            continue;

        if (strcmp(parsed_args[0], "cd") == 0)
            builtin_cd(parsed_args);
        else if (strcmp(parsed_args[0], "pwd") == 0)
            builtin_pwd();
        else if (strcmp(parsed_args[0], "exit") == 0)
            builtin_exit();
        if (parsed_args[1] == NULL)
        {
            chdir(getenv("HOME")); //go home if no argument
        }
        else
        {
            execute_command(parsed_args);
        }
    }
    return 0;
}