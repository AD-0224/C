#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name [100];
    int age;
    float height;
}
student;

int main ()
{
    student* s1 = malloc(sizeof(student));

    if (s1 == NULL)
    {
        printf ("Allocation error\n");
        return (1);
    }

    printf("Age: ");
    scanf("%d", &s1 -> age);

    printf("Name: ");
    scanf("%s", s1 -> name);

    printf("Height: ");
    scanf("%f", &s1 -> height);

    printf("The student's name is %s s(he) is %d years old, and %.2f cm tall \n", s1 -> name, s1 -> age, s1 -> height);

    free (s1);
    return (0);
}