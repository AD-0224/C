#include <unistd.h>

int main (int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc == 3)
	{
		while (argv[1][i] && argv[2][j]) //on a pas fini de les parcourir
		{
			if (argv[1][i] == argv[2][j]) //si les caractere correspondent
				i++;
			j++;
		}
		if (argv[1][i] == '\0') //quand on a fini de parcourir la chaine
		{
			j = 0; //Du début pour la reproduire
			while (argv[1][j]) //si on peut reproduire la seconde chaine, on l'affiche
			{
				write(1, &argv[1][j], 1);
				j++;
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}
