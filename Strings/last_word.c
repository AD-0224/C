#include <unistd.h>

void	last_word(char *str)
{
	int	j = 0;
	int	i = 0;
	while (str[i]) //pour trouver le debut du dernier mot
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] >= 33 && str[i + 1] <= 126) //Si on est sur un espace ou une tabutation et que celui d'apres est un caractere imprimable
			j = i + 1; //pointe vers le debut du mot suivant
		i++;
	}
	while (str[j] >= 33 && str[j] <= 126) //afficher le debut du dernier mot
	{
		write (1, &str[j], 1);
		j++;
	}
}

int	main (int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
