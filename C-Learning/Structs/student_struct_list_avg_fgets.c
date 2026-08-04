#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int age;
    float height;
    float average;
} student;

int main()
{
    int n;
    int c;
    float averageg = 0;

    printf("How many students are there? ");
    scanf("%d", &n);
    while ((c = getchar()) != '\n' && c != EOF);

    student* liste = malloc(sizeof(student) * n);
    if (liste == NULL)
    {
        printf("Allocation error\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("NAME : ");
        fgets(liste[i].name, sizeof(liste[i].name), stdin);
        size_t len = strlen(liste[i].name);
        if (len > 0 && liste[i].name[len - 1] == '\n')
        {
            liste[i].name[len - 1] = '\0';
        }

        printf("AGE : ");
        scanf("%d", &liste[i].age);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("TAILLE : ");
        scanf("%f", &liste[i].height);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("MOYENNE : ");
        scanf("%f", &liste[i].average);
        while ((c = getchar()) != '\n' && c != EOF);

        averageg += liste[i].average;
    }

    averageg /= n;

    printf("\n--- LISTES ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("NAME: %s | AGE: %d | HEIGHT: %.2f | AVERAGE: %.2f\n", liste[i].name, liste[i].age, liste[i].height, liste[i].average);
    }
    printf("\nThe overall average is : %.2f\n", averageg);
    free(liste);
    return 0;
}



