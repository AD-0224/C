#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[100];
    char type[20];
    int years;
    float note;
} book;

// Comparaison par note (ordre croissant)
int compare_by_note(const void* a, const void* b)
{
    float noteA = ((book*)a)->note;
    float noteB = ((book*)b)->note;
    if (noteA < noteB) return -1;
    if (noteA > noteB) return 1;
    return 0;
}

// Comparaison par titre (ordre alphabétique)
int compare_by_title(const void* a, const void* b)
{
    return strcmp(((book*)a)->title, ((book*)b)->title);
}

int main()
{
    int c;
    int n;
    float average = 0;
    int choice;

    printf("How many books? ");
    scanf("%d", &n);
    while ((c = getchar()) != '\n' && c != EOF);

    book* liste = malloc(sizeof(book) * n);
    if (liste == NULL)
    {
        printf("Allocation error\n");
        return 1;
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
        while ((c = getchar()) != '\n' && c != EOF);

        printf("NOTE: ");
        scanf("%f", &liste[i].note);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\nChoose sorting method:\n1 - By note (ascending)\n2 - By title (alphabetical)\nYour choice: ");
    scanf("%d", &choice);
    while ((c = getchar()) != '\n' && c != EOF);

    if (choice == 1)
    {
        qsort(liste, n, sizeof(book), compare_by_note);
    } else if (choice == 2) {
        qsort(liste, n, sizeof(book), compare_by_title);
    } else {
        printf("Invalid choice, displaying unsorted list.\n");
    }

    printf("\n--- LIST ---\n");
    for (int i = 0; i < n; i++) {
        average += liste[i].note;
        printf("TITLE: %s | TYPE: %s | YEARS: %d | NOTE: %.2f\n", liste[i].title, liste[i].type, liste[i].years, liste[i].note);
    }
    average /= n;
    printf("GLOBAL AVERAGE NOTE: %.2f\n", average);

    free(liste);
    return 0;
}