#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char title[100];
    char type[20];
    int years;
    float note;
}
book;

int main()
{
    int c;
    int n;
    float average = 0;

    printf("How many book? ");
    scanf("%d", &n);
    while(c = getchar() != '\n' && c != EOF);

    book* liste = malloc(sizeof(book) * n);
    if (liste == NULL)
    {
        printf("Allocation error");
        return (1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("BOOK N°: %d\n", i+1);

        printf("TITLE: ");
        fgets(liste[i].title, sizeof(liste[i].title), stdin);
        liste[i].title[strcspn(liste[i].title, "\n")] = 0;

        printf("TYPE: ");
        fgets(liste[i].type, sizeof(liste[i].type), stdin);
        liste[i].type[strcspn(liste[i].type, "\n")] = 0;

        printf("YEARS: ");
        scanf("%d", &liste[i].years);
        while(c = getchar() != '\n' && c != EOF);

        printf("NOTE: ");
        scanf("%f", &liste[i].note);
        while(c = getchar() != '\n' && c != EOF);
    }
    printf("---LISTE---\n");
    for (int i = 0; i < n; i++)
    {
        average += liste[i].note;
        printf("TITLE: %s | TYPE: %s | YEARS: %d | NOTE: %.2f\n", liste[i].title, liste[i].type, liste[i].years, liste[i].note);

    }
    average /= n;
    printf("GLOBALE AVERAGE: %.2f", average);
    free(liste);
    return (0);
}

