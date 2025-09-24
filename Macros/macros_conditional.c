
#include <stdio.h>

// #define DEBUG
// #define TEST

int main()
{
    printf("=== Program launch ===\n");

    #ifdef DEBUG
        printf("[DEBUG] Display of internal variables...\n");
    #endif

    #ifdef TEST
        printf("[TEST] Test mode: simulated data.\n");
    #endif

    printf("Main program.\n");
    return 0;
}
