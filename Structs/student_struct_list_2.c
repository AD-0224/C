#include <stdio.h>
#include<stdlib.h>

typedef struct 
{
    char nom[100];
    int age;
    float taille;
}
etudiant;

int main ()
{
    int n;
    printf("Combien y'a t'il d'etudiant? ");
    scanf("%d", &n); //stock la valeur dans n grace & qui nous indique l'adresse

    etudiant* liste = malloc(sizeof(etudiant) * n); //On initialise une liste contenant les données de la structure etudiant
    if (liste == NULL)
    {
        printf("Erreur d'allocation\n");
        return (1);
    }
    for (int i = 0; i < n;  i++) // On rempli n fois les infos de chaques etudiant
    {
        printf("L'etudiant: %d\n ", i + 1); //on veut commencer a etudiant 1

        printf("Nom: ");
        scanf("%s", liste[i].nom); //pas de & puisque c'est deja un tableau qui pointe sur la premiere valeur

        printf("Age: ");
        scanf("%d", &liste[i].age);

        printf("Taille: ");
        scanf("%f", &liste[i].taille);
    }
    printf("---LISTES DES ETUDIANTS---\n"); // on affiche un tableau 
    for (int i = 0; i < n; i++)
    {
        printf("NOM: %s | AGE: %d  | TAILLE: %.2f m\n", liste[i].nom, liste[i].age, liste[i].taille); //on veut la valur donc pas de &
    }
    free (liste);
    return (0);

}