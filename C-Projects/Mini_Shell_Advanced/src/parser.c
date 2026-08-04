#include "shell.h"

static int count_args(t_token *tokens);
static int check_syntax(t_token *tokens);

t_cmd *parseur(t_token *tokens)
{
    t_cmd *head;
    t_cmd *cmd;
    t_cmd *last;

    if(check_syntax(tokens))
    {
        printf("Syntax error\n");
        return NULL;
    }

    head = NULL;
    last = NULL;

    while (tokens)
    {
        cmd = malloc(sizeof(t_cmd));
        if (!cmd)
            return NULL;

        cmd->argv = malloc(sizeof(char *) * (count_args(tokens) + 1));
        cmd->infile = NULL;
        cmd->outfile = NULL;
        cmd->heredoc = NULL;
        cmd->append = 0;
        cmd->next = NULL;

        int i = 0;

        while (tokens && tokens->type != TOKEN_PIPE)
        {
            if (tokens->type == TOKEN_WORD)
            {
                cmd->argv[i] = strdup(tokens->value);
                i++;
            }

            else if (tokens->type == TOKEN_REDIR_IN)
            {
                tokens = tokens->next;

                if (tokens)
                    cmd->infile = strdup(tokens->value);
            }

            else if (tokens->type == TOKEN_REDIR_OUT)
            {
                tokens = tokens->next;

                if (tokens)
                    cmd->outfile = strdup(tokens->value);
            }

            else if (tokens->type == TOKEN_APPEND)
            {
                tokens = tokens->next;

                if (tokens)
                {
                    cmd->outfile = strdup(tokens->value);
                    cmd->append = 1;
                }
            }

            else if (tokens->type == TOKEN_HEREDOC)
            {
                tokens = tokens->next;

                if (tokens)
                    cmd->heredoc = strdup(tokens->value);
            }
            tokens = tokens->next;
        }
        cmd->argv[i] = NULL;

        if (!head)
            head = cmd;
        else
            last->next = cmd;
        last = cmd;

        if (tokens && tokens->type == TOKEN_PIPE)
            tokens = tokens->next;
    }
    return head;
}
static int count_args(t_token *tokens)
{
    int count = 0;

    while (tokens && tokens->type != TOKEN_PIPE)
    {
        if (tokens->type == TOKEN_WORD)
            count++;
        else if (tokens->type == TOKEN_REDIR_OUT || tokens->type == TOKEN_REDIR_IN || tokens->type== TOKEN_APPEND || tokens->type== TOKEN_HEREDOC)
            tokens = tokens->next;
        tokens = tokens->next;
    }
    return (count);
}
static int check_syntax(t_token *tokens)
{
    if (!tokens)
        return (0);

    // for the pipe of the beginning
    if (tokens->type == TOKEN_PIPE)
        return (1);

    while(tokens)
    {
        // last pipe
        if (tokens->type == TOKEN_PIPE && tokens->next == NULL)
            return (1);

        // two pipe in a row
        if (tokens->type == TOKEN_PIPE
            && tokens->next
            && tokens->next->type == TOKEN_PIPE)
            return (1);

        // file-free redirection
        if ((tokens->type == TOKEN_REDIR_IN
            || tokens->type == TOKEN_REDIR_OUT
            || tokens->type == TOKEN_APPEND
            || tokens->type == TOKEN_HEREDOC))
        {
            if (!tokens->next)
                return (1);

            if (tokens->next->type != TOKEN_WORD)
                return (1);
        }
        tokens = tokens->next;
    }
    return (0);
}

void free_cmd(t_cmd *cmds)
{
    t_cmd *tmp;
    int i;

    while (cmds)
    {
        i = 0;
        tmp = cmds->next;
        if (cmds->argv)
        {
            while (cmds->argv[i])
            {
                free(cmds->argv[i]);
                i++;
            }
            free(cmds->argv);
        }
        if (cmds->infile)
            free(cmds->infile);

        if (cmds->outfile)
            free(cmds->outfile);

        if (cmds->heredoc)
            free(cmds->heredoc);
        free(cmds);
        cmds = tmp;
    }
}