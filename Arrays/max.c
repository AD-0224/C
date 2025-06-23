int	max (int *tab, unsigned int len)
{
	int	result;
	unsigned int	i = 0;

	if (len == 0)
		return (0); 
	result = tab[i]; // par defaut on initialise result au debut du tableau
	while (i < len) //Tant qu'on a pas tout parcouru
	{
		if (result < tab[i]) 
			result = tab[i];
		i++;
	}
	return (result);
}
// #include<stdio.h>
// int main (void)
// {
// 	int tab [] = {4, 9, -2, 7, 5};
// 	printf("%d", max(tab, 5));
// 	return (0);
// }