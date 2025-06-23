
char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s2[i] != '\0') //s2 vers s1
	{
		s1[i] = s2[i]; //copie caractere par caractere
		i++;
	}
	s1[i] = '\0'; //ajout du caractere de fin de chaine
	return (s1); //retourne la chaine de destination 
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