#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc == 2)
	{
		while (argv[1][i]) //parcourt la chaine pour determiner sa longueur
			i++;
		while (i >= 0) //affiche les caracteres en ordre inverse
			write (1, &argv[1][--i], 1); //affiche le caractere actuel et decremente i
	}
	write(1, "\n", 1);
	return (0);
}

