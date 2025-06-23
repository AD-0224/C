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

	while (*str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int main (int argc, char **argv)
{
    int i = 1; //premier multiplicateur
    int n = ft_atoi(argv[1]); //celui dont on veut trouver la table
    if (argc == 2)
    {
        while (i <= 9) //entre 1 et 9
        {
            ft_putnbr(i); //chiffre
            ft_putchar(' ');
            ft_putchar('x');
            ft_putchar(' ');
            ft_putnbr(n); //chiffre
            ft_putchar(' ');
            ft_putchar('=');
            ft_putchar(' ');
            ft_putnbr(i * n); //chiffre
            ft_putchar('\n');
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}