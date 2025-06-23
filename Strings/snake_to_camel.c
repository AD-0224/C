#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == '_') //si c'est égale a un _ alors on passe au suivant qu'on met en majuscule
			{
				i++;
				argv[1][i] -= 32;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
