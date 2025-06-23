#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int flg;

    if (argc == 2)
    {
        flg = 0;
        i = 0; 

        while (argv[1][i] == ' ' || argv[1][i] == '\t') //on ignore les espaces et tabulations du début pour commencer avec un caractere
            i++;
        while (argv[1][i])
        {
            if (argv[1][i] == ' ' || argv[1][i] == '\t') //si on en voit 
                flg = 1;
            if (!(argv[1][i] == ' ' || argv[1][i] == '\t')) //si c'est un caractere et qu'on a un flag, on met un espace
            {
                if (flg) //si on a rencontré un espace ou une tabulation
                    write (1, " ", 1); //on ecrit un espace
                flg = 0; //on remet a 0 pour reparcourir la chaine
                write (1, &argv[1][i], 1); //on écrit le caractere actuel
            }
            i++; 
        }
    }
    write(1, "\n", 1);
    return (0); //le programm s'est terminé avec succés
}