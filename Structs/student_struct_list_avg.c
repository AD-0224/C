#include<stdio.h>
#include <stdlib.h>

typedef struct
{
    char nom[100];
    int age;
    float taille;
    float moyenne;
}
etudiant;

int main ()
{
    int n;
    float generale = 0;
    etudiant* liste = malloc(sizeof(etudiant) * n);
    if (liste == NULL)
    {
        printf("Erreur d'allocation\n");
        return (1);
    }
    printf("Nombre d'etudiants: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Etudiant: %d \n", i+1);

        printf("NOM: ");
        scanf("%s", liste[i].nom);

        printf("AGE: ");
        scanf("%d", &liste[i].age);

        printf ("TAILLE: ");
        scanf("%f", &liste[i].taille);

        printf("MOYENNE: ");
        scanf("%f", &liste[i].moyenne);
    }

    for (int i = 0; i < n; i++)
    {
        generale += (liste[i].moyenne);
        printf("NOM: %s | AGE: %d | TAILLE: %.2f | MOYENNE: %.2f\n", liste[i].nom, liste[i].age, liste[i].taille, liste[i].moyenne);
        
    }
    generale /= n;
    printf("La moyenne des etudiants est de: %.2f", generale);
    free (liste);
    return (0);
}
