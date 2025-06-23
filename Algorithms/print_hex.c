#include <unistd.h>

void    print_hex(int n)
{
    char hex_digit[] = "0123456789abcdef"; //tableau
    if (n >= 16) //base
        print_hex (n / 16); //divise par 16
    write(1, &hex_digit[n % 16], 1); //recupere le dernier chiffre de l'adresse du tableau 
}
int main (int argc, char **argv)
{
    if (argc == 2)
    {
        int n = 0; // Variable pour stocker le nombre converti
        int i = 0;
        while (argv[1][i] != '\0')
        {
            n = n * 10 + (argv[1][i] - '0'); // Convertit chaque caractère en entier et construit le nombre
            i++;
        }
        print_hex(n);
    }
    write(1, "\n", 1);
    return (0);
}