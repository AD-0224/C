
#include <stdio.h>

// Active un mode en décommentant la ligne souhaitée
// #define DEBUG
// #define TEST

int main()
{
    printf("=== Lancement du programme ===\n");

    #ifdef DEBUG
        printf("[DEBUG] Affichage des variables internes...\n");
    #endif

    #ifdef TEST
        printf("[TEST] Mode test : données simulées.\n");
    #endif

    printf("Programme principal.\n");

    return 0;
}
