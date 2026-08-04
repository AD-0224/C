
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char    name[100];
    int     age;
    float   height;
    float   average;
}
student;

int main ()
{
    int c;
    int n;
    float generaleAverage = 0;
    
    printf("How many student? ");
    scanf("%d", &n);
    while(c = getchar() != '\n' && c != EOF);


    student* liste = malloc(sizeof(student) * n);
    if (liste == NULL)
    {
        printf("Allocation error");
        return (1);
    }

    for(int i = 0; i < n; i++)
    {

        printf("Student: %d\n", i+1);

        printf("NAME: ");
        fgets(liste[i].name, sizeof(liste[i].name), stdin);
        liste[i].name[strcspn(liste[i].name, "\n")] = 0;

        printf("AGE: ");
        scanf("%d", &liste[i].age);
        while(c = getchar() != '\n' && c != EOF); 

        printf("HEIGHT: ");
        scanf("%f", &liste[i].height);
        while(c = getchar() != '\n' && c != EOF);

        printf("AVERAGE: ");
        scanf("%f", &liste[i].average);
        while(c = getchar() != '\n' && c != EOF);
    }

     for(int i = 0; i < n; i++)
     {
        generaleAverage += liste[i].average;
        printf("NAME: %s | AGE: %d | HEIGHT: %.2f | AVERAGE: %.2f\n", liste[i].name, liste[i].age, liste[i].height, liste[i].average);

     }
    generaleAverage /= n;
    printf("The generale average = %.2f", generaleAverage);
    free (liste);
}

