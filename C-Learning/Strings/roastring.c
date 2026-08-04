#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int start = 0;
	int len = 0;

	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		start = i;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t') 
		{
			len++;
			i++;
		}
		while (argv[1][i])
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				write(1, &argv[1][i++], 1);
			write(1, " ", 1);
		}
		write(1, &argv[1][start], len);
	}
	write(1, "\n", 1);
	return (0);
}

