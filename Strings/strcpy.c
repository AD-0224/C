char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
// #include <string.h>
// #include <stdio.h>
// int main (void)
// {
// 	char a[100], b[100];
// 	printf("%s\n", ft_strcpy(a, "SALUT"));
// 	printf("%s\n", strcpy(b, "SALUT"));
// 	return(0);
// }