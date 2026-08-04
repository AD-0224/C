#include "shell.h"

static char *expand_word(char *word)
{
    char *result;
    char buf[64];
    size_t cap;
    size_t len;
    char *val;
    char *name;
    int i;
    int j;

    cap = strlen(word) * 2 + 64;
    result = malloc(cap);
    if (!result)
        return (word);
    len = 0;
    i = 0;
    while (word[i])
    {
        if (word[i] == '\x01' && word[i + 1] == '$')
        {
            result[len++] = '$';
            i += 2;
        }
        else if (word[i] == '$' && (word[i + 1] == '_' || word[i + 1] == '?'
                || word[i + 1] == '$' || (word[i + 1] >= 'A' && word[i + 1] <= 'Z')
                || (word[i + 1] >= 'a' && word[i + 1] <= 'z')))
        {
            i++;
            if (word[i] == '?')
            {
                sprintf(buf, "%d", g_exit_status);
                val = buf;
                i++;
            }
            else if (word[i] == '$')
            {
                sprintf(buf, "%d", getpid());
                val = buf;
                i++;
            }
            else
            {
                j = 0;
                name = malloc(strlen(word + i) + 1);
                while (word[i] && (word[i] == '_' || (word[i] >= 'A' && word[i] <= 'Z')
                        || (word[i] >= 'a' && word[i] <= 'z')
                        || (word[i] >= '0' && word[i] <= '9')))
                    name[j++] = word[i++];
                name[j] = '\0';
                val = getenv(name);
                if (!val)
                    val = "";
                free(name);
            }
            while (len + strlen(val) + 1 >= cap)
            {
                cap *= 2;
                result = realloc(result, cap);
            }
            strcpy(result + len, val);
            len += strlen(val);
        }
        else
            result[len++] = word[i++];
    }
    result[len] = '\0';
    free(word);
    return (result);
}

void expand_cmd(t_cmd *cmds)
{
    int i;

    while (cmds)
    {
        i = 0;
        while (cmds->argv && cmds->argv[i])
        {
            cmds->argv[i] = expand_word(cmds->argv[i]);
            i++;
        }
        if (cmds->infile)
            cmds->infile = expand_word(cmds->infile);
        if (cmds->outfile)
            cmds->outfile = expand_word(cmds->outfile);
        cmds = cmds->next;
    }
}