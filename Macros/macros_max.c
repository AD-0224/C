#include<stdio.h>

#define MAX(a,b) ((a > b) ? a : b)
int main ()
{
    printf("%d\n", MAX(6, 98));
    printf("%d\n", MAX(-6, 8));
    printf("%d\n", MAX(4, 9));
}