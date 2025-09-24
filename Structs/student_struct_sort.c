#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[100];
    float average;
}
student;

int compare_by_note(const void *a, const void *b)
{
    const student *studentA = (const student*)a; 
    const student *studentB = (const student*)b;

    if (studentA->average < studentB->average) return (-1);
    if (studentA->average > studentB->average)return (1);
    return(0);
}

int compare_by_title(const void *a, const void *b)
{
    const student *studentA = (const student*)a;
    const student *studentB = (const student*)b;

    return (strcmp(studentA ->name, studentB -> name));
}

int main ()
{
    int n;
    int choice; 

    printf("How many student? ");
    scanf("%d", &n);

    student* tab = malloc(sizeof(student) * n);
    if (tab == NULL)
    {
        printf("Allocation error");
        return (1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Student n°: %d\n", i + 1);

        printf("NAME: ");
        scanf("%s", tab[i].name);

        printf("AVERAGE: ");
        scanf("%f", &tab[i].average);
    }

    printf("\nChoose sorting method:\n1 - By note (ascending)\n2 - By title (alphabetical)\nYour choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        qsort(tab, n, sizeof(student), compare_by_note);
    }
    else if (choice == 2)
    {
        qsort(tab, n, sizeof(student), compare_by_title);
    }
    else 
    {
        printf("Invalid choice, displaying unsorted list.\n");
    }

    printf("--Sorted list--\n");
    for (int i = 0; i < n; i++)
    {
        printf("NAME: %s | AVERAGE: %.2f\n", tab[i].name, tab[i].average);
    }
    free(tab);
    return (0);
}