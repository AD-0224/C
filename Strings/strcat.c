
//concaténation de chaînes

char *my_strcat(char *dest, const char *src)
{
    char *ptr = dest;

    // Avance jusqu'à la fin de la chaîne dest
    while (*ptr != '\0')
    {
        ptr++;
    }

    // Copie src à la fin de dest
    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0'; // Termine la chaîne
    return dest;
}
