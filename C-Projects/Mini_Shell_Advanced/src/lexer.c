#include "shell.h"

static t_token *new_token(char *value, t_token_type type);
static void add_token(t_token **head, t_token *new);
static char *read_word(char **line);
static t_token *last_token(t_token *t);

static t_token *new_token(char *value, t_token_type type)
{
    t_token *t = malloc(sizeof(t_token));
    if (!t)
        return NULL;

    t->value = value;
    t->type = type;
    t->is_redir_target = 0;
    t->next = NULL;
    return t;
}

static void add_token(t_token **head, t_token *new)
{
    t_token *tmp;

    if (!*head)
    {
        *head = new;
        return;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void free_tokens(t_token *tokens)
{
    t_token *tmp;

    while (tokens)
    {
        tmp = tokens->next;
        free(tokens->value);
        free(tokens);
        tokens = tmp;
    }
}

t_token *lexer(char *line)
{
    t_token *tokens = NULL;
    char *word;

    while (*line)
    {
        while (*line == ' ')
            line++;

        if (*line == '\0')
            break;

        // PIPE
        if (*line == '|')
        {
            add_token(&tokens, new_token(strdup("|"), TOKEN_PIPE));
            line++;
            continue;
        }

        // REDIRECTIONS
        if (*line == '>')
        {
            if (*(line + 1) == '>')
            {
                add_token(&tokens, new_token(strdup(">>"), TOKEN_APPEND));
                line += 2;
            }
            else
            {
                add_token(&tokens, new_token(strdup(">"), TOKEN_REDIR_OUT));
                line++;
            }
            continue;
        }

        if (*line == '<')
        {
            if (*(line + 1) == '<')
            {
                add_token(&tokens, new_token(strdup("<<"), TOKEN_HEREDOC));
                line += 2;
            }
            else
            {
                add_token(&tokens, new_token(strdup("<"), TOKEN_REDIR_IN));
                line++;
            }
            continue;
        }

        // WORD
        word = read_word(&line);

        int is_target = 0;
        t_token *last = last_token(tokens);

        if (last && (last->type == TOKEN_REDIR_IN
                  || last->type == TOKEN_REDIR_OUT
                  || last->type == TOKEN_APPEND
                  || last->type == TOKEN_HEREDOC))
        {
            is_target = 1;
        }

        t_token *new = new_token(word, TOKEN_WORD);
        new->is_redir_target = is_target;

        add_token(&tokens, new);
    }
    return tokens;
}

static char *read_word(char **line)
{
    size_t cap = 64;
    char *word = malloc(cap);
    int i = 0;

    while (**line && **line != ' ' && **line != '\n' && **line != '|' && **line != '<' && **line != '>')
    {
        if ((size_t)i + 2 >= cap)
        {
            cap *= 2;
            word = realloc(word, cap);
        }
        if (**line == '\'')
        {
            (*line)++;
            while (**line && **line != '\'')
            {
                if ((size_t)i + 2 >= cap)
                {
                    cap *= 2;
                    word = realloc(word, cap);
                }
                if (**line == '$')
                    word[i++] = '\x01';
                word[i++] = *(*line)++;
            }
            if (**line == '\'')
                (*line)++;
        }
        else if (**line == '"')
        {
            (*line)++;
            while (**line && **line != '"')
            {
                if ((size_t)i + 2 >= cap)
                {
                    cap *= 2;
                    word = realloc(word, cap);
                }
                word[i++] = *(*line)++;
            }
            if (**line == '"')
                (*line)++;
        }
        else
        {
            word[i++] = *(*line)++;
        }
    }
    word[i] = '\0';
    return word;
}

static t_token *last_token(t_token *t)
{
    if (!t)
        return NULL;

    while (t->next)
        t = t->next;

    return t;
}
void print_tokens(t_token *t)
{
    while (t)
    {
        if (t->type == TOKEN_WORD)
            printf("WORD(%s)\n", t->value);
        else if (t->type == TOKEN_PIPE)
            printf("PIPE\n");
        else if (t->type == TOKEN_REDIR_IN)
            printf("REDIR_IN\n");
        else if (t->type == TOKEN_REDIR_OUT)
            printf("REDIR_OUT\n");
        else if (t->type == TOKEN_APPEND)
            printf("APPEND\n");
        else if (t->type == TOKEN_HEREDOC)
            printf("HEREDOC\n");

        t = t->next;
    }
}