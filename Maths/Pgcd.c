//Plus grand denominateur commun

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int nbr1 = atoi (argv[1]);
    int nbr2 = atoi (argv[2]);
    int temp;

    if (argc == 3)
    {
        if (nbr1 > 0 && nbr2 > 0) //Si ils sont tous les 2 positifs
        {
            while (nbr2 != 0) //condition pour de theoreme euclide
            {
                temp = nbr2;
                nbr2 = nbr1 % nbr2;
                nbr1 = temp; 
            }
            printf("%d", nbr1);
        }
    }
    printf("\n");
    return (0);
}