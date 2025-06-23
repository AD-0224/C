char *ft_strrev(char *str)
{
	int	i = 0;
	int	len = 0;
	char	temp;

	if (!str)
		return (0); //Si elle est nulle
	while (str[len])
		len++; //Compteur
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];  // Remplace le caractère à la position i par celui de la fin
		str[len - 1 - i] = temp;// Place l'ancien caractère à la fin
		i++;
	}
	return (str);
}
