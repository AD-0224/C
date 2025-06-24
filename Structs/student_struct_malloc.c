#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nom [100];
    int age;
    float taille;
}
etudiant;

int main ()
{
    etudiant* e1 = malloc(sizeof(etudiant));

    if (e1 == NULL)
    {
        printf ("Erreur d'allocation\n");
        return (1);
    }

    printf("Age: ");
    scanf("%d", &e1 -> age);

    printf("Nom: ");
    scanf("%s", e1 -> nom);

    printf("Taille: ");
    scanf("%f", &e1 -> taille);

    printf("L'etudiant s'appelle %s il a %d ans, et fait %.2f m \n", e1 -> nom, e1 -> age, e1 -> taille);

    free (e1);
    return (0);
}