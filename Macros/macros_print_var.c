#include <stdio.h>

#define PRINT_VAR(age, poids)

int main()
{
    int age = 23;
    float poids = 55.2;

    // Utilisation de la macro
    PRINT_VAR(age);
    PRINT_VAR(poids);

    return 0;
}