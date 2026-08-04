#ifndef SHELL_H
#define SHELL_H

#define PROMPT "myshelladvanced>"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

// exit status de la derniere commande (pour $?), definie dans main.c
extern int g_exit_status;
// drapeau leve par Ctrl-C pendant la lecture d'un heredoc, definie dans main.c
extern volatile sig_atomic_t g_heredoc_interrupted;

// TOKEN TYPES
typedef enum e_token_type
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIR_IN,
    TOKEN_REDIR_OUT,
    TOKEN_APPEND,
    TOKEN_HEREDOC
} t_token_type;

// TOKEN STRUCT
typedef struct s_token
{
    char *value;
    t_token_type type;
    int is_redir_target;
    struct s_token *next;
} t_token;

// PARSING
typedef struct s_cmd
{
    char            **argv;
    char            *infile;
    char            *outfile;
    char            *heredoc;
    int             append;
    struct s_cmd    *next;

} t_cmd;

t_cmd  *parseur(t_token *tokens);
void    free_cmd(t_cmd *cmds);

// FUNCTIONS
void shell_loop(void);
void execute_command(char *line);
char **split_simple(char *line);
char *build_prompt(void);

// LEXER
t_token *lexer(char *line);
void free_tokens(t_token *tokens);
void print_tokens(t_token *t);

// EXEC (exec.c)
void    execute_pipeline(t_cmd *cmds);
void    apply_redirections(t_cmd *cmd);
char    *find_path(char *cmd);

// BUILTINS (builtins.c)
int     is_builtin(char *cmd);
int     exec_builtin(t_cmd *cmd);

// EXPANSION (expand.c)
void    expand_cmd(t_cmd *cmds);

// SIGNAUX (signals.c)
void    setup_signals_parent(void);
void    setup_signals_heredoc(void);
void    setup_signals_child(void);

// HEREDOC (heredoc.c)
int     handle_heredocs(t_cmd *cmds);

#endif