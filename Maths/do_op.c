
#include <stdio.h> //Pour utiliser printf
#include <stdlib.h> //Pour utiliser atoi

int	main (int argc, char **argv)
{
	if (argc == 4) // Si on a 4 argument 
	{
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		if (argv[2][0] == '-')
            printf("%d", (atoi(argv[1]) - atoi(argv[3])));
	    if (argv[2][0] == '*')
            printf("%d", (atoi(argv[1]) * atoi(argv[3])));
		if (argv[2][0] == '/')
            printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		if (argv[2][0] == '%')
            printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	}
	printf("\n");
	return (0);
}






