
int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i); //retourne le nombre d'elements
}

// int main(int argc, char *argv[])
// {
//     char chaine[] = "Salut";
//     int longueurChaine = 0;

//     // On récupère la longueur de la chaîne dans longueurChaine
//     longueurChaine = strlen(chaine);

//     // On affiche la longueur de la chaîne
//     printf("La chaine %s fait %d caracteres de long", chaine, longueurChaine);

//     return 0;
// }