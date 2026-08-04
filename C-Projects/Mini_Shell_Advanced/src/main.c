#include "shell.h"

int g_exit_status = 0;
volatile sig_atomic_t g_heredoc_interrupted = 0;

int main(void)
{
    setup_signals_parent();
    shell_loop();
    return (g_exit_status);
}