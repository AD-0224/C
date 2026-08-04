#include <stdio.h>

#define HELLO() printf("Hello\n");\
                printf("I'm sick\n");\
                printf("Really\n");
int main ()
{
    HELLO()
    return (0);
}