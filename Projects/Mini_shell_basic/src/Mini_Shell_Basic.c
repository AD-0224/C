#include "MINI_SHELL_BASIC.h"

char **parse_input(char *input, char **args)
{
    int i = 0;
    const char *separators = " \n";
    char *strToken = strtok(input, separators); //word = token; and the first call

    while (strToken != NULL && i < MAX_ARGS - 1) //Leave the '\0' at the end 
    {
        args[i++] = strToken;
        strToken = strtok (NULL, separators); //Next call into the separators
    }
    args[i] = NULL; //Add NULL at the end 
    return args;
}

int is_builtin(char *cmd)
{
    if ((strcmp(cmd, "cd")== 0) || (strcmp(cmd, "pwd")== 0) || (strcmp(cmd, "exit")== 0))
        return 1;
    else 
        return 0;
}
// In exit case 
int builtin_exit() 
{
    printf("Goodbye !");
    exit(0);
}

// In pwd case display the current folder 
int builtin_pwd() 
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
    return 0;
}

//Change the folder
int builtin_cd(char **args)
{
    if (args[1] == NULL)
    {
        // printf("Missing arguments\n");
        // return 1;
        chdir(getenv("HOME")); //expected behavior
        return 0;
    }

    if (chdir(args[1]) != 0)
    {
        perror("cd failed");
        return 1;
    }
    return 0;
}

int execute_command(char **args)
{
   pid_t pid = fork();
    if (pid == 0) //son
    {
        execvp(args[0], args);
        perror("exec failed");
        exit(1);
    }
    else if (pid > 0) //father
    {
        wait(NULL);
        return 0;
    }
    else
    {
        perror ("fork failed");
        return 1;
    }
}
