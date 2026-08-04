#include <unistd.h>

int main (int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc == 3)
	{
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j]) 
				i++;
			j++;
		}
		if (argv[1][i] == '\0')
		{
			j = 0;
			while (argv[1][j])
			{
				write(1, &argv[1][j], 1);
				j++;
			}
		}
	}
	write (1, "\n", 1);
	return (0);
}
