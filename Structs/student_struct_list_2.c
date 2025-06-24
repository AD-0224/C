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
    scanf("%d", &n);

    etudiant* liste = malloc(sizeof(etudiant) * n);
    if (liste == NULL)
    {
        printf("Erreur d'allocation\n");
        return (1);
    }
    for (int i = 0; i < n;  i++)
    {
        printf("L'etudiant: %d\n ", i + 1);

        printf("Nom: ");
        scanf("%s", liste[i].nom);
        printf("Age: ");
        scanf("%d", &liste[i].age);

        printf("Taille: ");
        scanf("%f", &liste[i].taille);
    }
    printf("---LISTES DES ETUDIANTS---\n");
    for (int i = 0; i < n; i++)
    {
        printf("NOM: %s | AGE: %d  | TAILLE: %.2f m\n", liste[i].nom, liste[i].age, liste[i].taille);
    }
    free (liste);
    return (0);

}