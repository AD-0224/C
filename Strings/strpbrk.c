

// La fonction strpbrk recherche dans la chaîne s1 le premier caractère qui appartient
// à l'ensemble de caractères spécifié dans la chaîne s2. 

#include <stddef.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	size_t	i;
	size_t j;
	
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}


// #include<stdio.h>
// #include<string.h>

// int main (int ac, char **av)
// {
// 	(void)ac;
// 	printf("%s\n", ft_strpbrk(av[1], av[2]));
// 	printf("%s\n", strpbrk(av[1], av[2]));
// 	return(0);
// }