#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;

	if (argc == 4 && !argv[2][1] && !argv[3][1]) //verifie si le 2 et 3 sont des caracteres uniques (si[2][1] n'existe pas)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0]) //si le caractere actuel est egale au caractere a rechercher argv[2][0]
				argv[1][i] = argv [3][0]; //remplace le caractere par le caractere de remplacement argv[3][0] dans la chaine
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

