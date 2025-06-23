int	ft_atoi(char *str)
{
	int	result = 0;
	int	sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))// white space
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+') 
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0'; //decalle vers la gauche pour laisser de la place  et converti en ASCII
		str++;
	}
	return (sign * result);
}

// #include <stdio.h>
// int main (void)
// {
// 	printf("%d", ft_atoi("42"));
// 	return 0;
// }