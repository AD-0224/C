#include<stddef.h>

//  chercher un caractère

char *my_strchr(const char *str, int c) {
    while (*str != '\0')
    {
        if (*str == (char)c)
        {
            return (char *)str;  // cast pour retourner un pointeur non const
        }
        str++;
    }

    // Vérifie si c est '\0'
    if (c == '\0')
    {
        return (char *)str;
    }

    return NULL;
}
