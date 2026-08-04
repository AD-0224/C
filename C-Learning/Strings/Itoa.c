#include <stdlib.h> 

int	ft_intlen(int n)
{
	int	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len = ft_intlen(nbr);
	char	*str = malloc(sizeof(char) * (len + 1)); 
	long	nb = nbr; 
	
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-'; 
		nb = -nb;     
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

// #include <stdio.h>

// char *ft_itoa(int n);

// int main(void)
// {
//     printf("%s\n", ft_itoa(0));
//     printf("%s\n", ft_itoa(123));
//     printf("%s\n", ft_itoa(-456));
//     printf("%s\n", ft_itoa(2147483647));
//     printf("%s\n", ft_itoa(-2147483648));
//     return (0);
// }