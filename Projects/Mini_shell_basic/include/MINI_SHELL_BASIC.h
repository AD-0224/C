#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

#define MAX_ARGS 213

#ifndef MINI_SHELL_BASIC_H
#define MINI_SHELL_BASIC_H

char **parse_input(char *input, char **args);
int is_builtin(char *cmd);
int builtin_exit();
int builtin_pwd();
int builtin_cd(char **args);
int execute_command(char **args);

#endif