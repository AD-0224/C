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
	int i = 2;

	if (n < 2)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	sum = 0;
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
	ft_putnbr(sum); 
	write(1, "\n", 1);
	return (0);
}
