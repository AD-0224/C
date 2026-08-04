#include "shell.h"
#include <readline/readline.h>

static void handle_sigint(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

static void handle_sigint_heredoc(int sig)
{
    (void)sig;
    g_heredoc_interrupted = 1;
}

void setup_signals_parent(void)
{
    struct sigaction sa_int;

    rl_catch_signals = 0;
    sa_int.sa_handler = handle_sigint;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

    signal(SIGQUIT, SIG_IGN);
}

void setup_signals_heredoc(void)
{
    struct sigaction sa_int;

    sa_int.sa_handler = handle_sigint_heredoc;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);
}

void setup_signals_child(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}