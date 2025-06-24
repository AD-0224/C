char *ft_strrev(char *str)
{
	int	i = 0;
	int	len = 0;
	char	temp;

	if (!str)
		return (0);
	while (str[len])
		len++;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}
