#include <stdio.h>
#include<stdlib.h>

typedef struct 
{
    char name[100];
    int age;
    float height;
}
student;

int main ()
{
    int n;
    printf("How many students are there? ");
    scanf(" %d", &n);

    student* liste = malloc(sizeof(student) * n);
    if (liste == NULL)
    {
        printf("Allocation error\n");
        return (1);
    }
    for (int i = 0; i < n;  i++)
    {
        printf("The student: %d\n ", i + 1);

        printf("Name: ");
        scanf("%s", liste[i].name);
        printf("Age: ");
        scanf("%d", &liste[i].age);

        printf("Height: ");
        scanf("%f", &liste[i].height);
    }
    printf("---STUDENT LISTS---\n");
    for (int i = 0; i < n; i++)
    {
        printf("NAME: %s | AGE: %d  | HEIGHT: %.2f m\n", liste[i].name, liste[i].age, liste[i].height);
    }
    free (liste);
    return (0);
}