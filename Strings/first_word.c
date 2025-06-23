#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i] == 32 || argv[1][i] == 9) 
			i++;
		while (argv[1][i] && argv[1][i] != 32 && argv[1][i] != 9) //si elle n'est pas vide et que c'est ni un espace ni une tabulation 
		{
			write (1, &argv[1][i], 1); //on ecrit le caractere
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

