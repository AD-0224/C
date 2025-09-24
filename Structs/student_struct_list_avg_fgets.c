#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nom[100];
    int age;
    float taille;
    float moyenne;
} etudiant;

int main()
{
    int n;
    int c;
    float moyenneg = 0;

    printf("Combien y a-t-il d'étudiants ? ");
    scanf("%d", &n);
    while ((c = getchar()) != '\n' && c != EOF);

    etudiant* liste = malloc(sizeof(etudiant) * n);
    if (liste == NULL)
    {
        printf("Erreur d'allocation\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nÉtudiant %d\n", i + 1);

        printf("NOM : ");
        fgets(liste[i].nom, sizeof(liste[i].nom), stdin);
        size_t len = strlen(liste[i].nom);
        if (len > 0 && liste[i].nom[len - 1] == '\n')
        {
            liste[i].nom[len - 1] = '\0';
        }

        printf("AGE : ");
        scanf("%d", &liste[i].age);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("TAILLE : ");
        scanf("%f", &liste[i].taille);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("MOYENNE : ");
        scanf("%f", &liste[i].moyenne);
        while ((c = getchar()) != '\n' && c != EOF);

        moyenneg += liste[i].moyenne;
    }

    moyenneg /= n;

    printf("\n--- LISTES ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("NOM: %s | AGE: %d | TAILLE: %.2f | MOYENNE: %.2f\n", liste[i].nom, liste[i].age, liste[i].taille, liste[i].moyenne);
    }
    printf("\nLa moyenne générale est de : %.2f\n", moyenneg);
    free(liste);
    return 0;
}



