#include <stdlib.h>

char	**ft_split(char *s)
{
	char	**tab;
	int		i = 0;
    int     j = 0; 
    int     k = 0;

    tab = malloc(sizeof(char *) * 256);
	if (!s || !tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		tab[j] = malloc(4096);
		if (!tab[j])
			return (NULL);
		k = 0;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			tab[j][k++] = s[i++];
		tab[j++][k] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}

// #include <stdio.h>

// int main(void)
// {
// 	char **s = ft_split("one two three");
// 	while (*s) printf("%s\n", *s++);
// }
