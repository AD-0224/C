 //Calcule la somme de tous les nombres premiers inférieurs ou égaux à ce nombre.

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		ft_atoi(char *str)
{
	int res = 0;

	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int		is_prime(int n)
{
	int i = 2; //diviseur

	if (n < 2)
		return (0);  // les nombres < 2 ne sont pas premiers
	while (i * i <= n) //on a depassé la racine carrée de n donc on arrete a ce moment la 
	{
		if (n % i == 0) //si il est divisible pas premier
			return (0);
		i++; //on continue a chercher 
	}
	return (1); //Si on n’a trouvé aucun diviseur jusqu’à √n, alors le nombre est premier
}

int	main(int argc, char **argv)
{
	int	n;
	int	sum = 0; //somme des nombres premier
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
    n = ft_atoi(argv[1]);
	while (n > 0)
	{
		if (is_prime(n))
			sum = sum + n;
		n--;
	}
	ft_putnbr(sum); //Afficher la somme des nombres premiers
	write(1, "\n", 1);
	return (0);
}
