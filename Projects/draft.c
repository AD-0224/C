#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int age = 21;

    int *p1 = &age;
    int **p2 = &p1;

    printf("adresse de age: %x\n", p1);
    printf("adresse de p1: %x\n", p2);

    printf("Valeur de age en utilisant un seul pointeur : %d\n", *p1);
    printf("Valeur de age en utilisant un seul pointeur : %d\n", **p2);

    return 0;

}