#include<stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[100];
    int age;
    float height;
    float average;
}
student;

int main ()
{
    int n;
    float general = 0;
    student* liste = malloc(sizeof(student) * n);
    if (liste == NULL)
    {
        printf("Allocation error\n");
        return (1);
    }
    printf("Number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Student: %d \n", i+1);

        printf("NAME: ");
        scanf("%s", liste[i].name);

        printf("AGE: ");
        scanf("%d", &liste[i].age);

        printf ("HEIGHT: ");
        scanf("%f", &liste[i].height);

        printf("AVERAGE: ");
        scanf("%f", &liste[i].average);
    }

    for (int i = 0; i < n; i++)
    {
        general += (liste[i].average);
        printf("NAME: %s | AGE: %d | HEIGHT: %.2f | AVERAGE: %.2f\n", liste[i].name, liste[i].age, liste[i].height, liste[i].average);
        
    }
    general /= n;
    printf("The average student is: %.2f", general);
    free (liste);
    return (0);
}
