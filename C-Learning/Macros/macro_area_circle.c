#include<stdio.h>

#define PI 3.14159
#define AREA_CIRCLE(r) (PI * (r) * (r))

int main ()
{
    double r = 0;
    printf ("Donner le rayon svp\n");
    scanf("%lf", &r);
    printf("L'air est %lf", AREA_CIRCLE(r));
    return (0);
}