// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node
// {
//     int data;
//     struct Node *next;
// } Node;

// int main() {
//     // Créer le premier noeud
//     Node *premier = malloc(sizeof(Node));
//     premier->data = 50;
//     premier->next = NULL;
    
//     // Créer le deuxième noeud
//     Node *deuxieme = malloc(sizeof(Node));
//     deuxieme->data = 100;
//     deuxieme->next = NULL;

//     Node *troisieme = malloc(sizeof(Node));
//     troisieme->data = 150;
//     troisieme->next = NULL;
    
//     // Les relier
//     premier->next = deuxieme;
//     deuxieme-> next = troisieme;
    
//     // Afficher
//     Node *current = premier;
//     while (current != NULL)
//     {
//         printf("%d ->", current->data);
//         current = current->next;
//     }
//     printf("Null");
    
    
//     // Libérer
//     free(troisieme);
//     free(deuxieme);
//     free(premier);
    
//     return 0;
// }

#include<stdio.h>

int main (void)
{
    int année = 0;

    printf("Année: %d", année);
    scanf("%d", &année);

    if (année % 4 == 0 && année % 100 != 0 || année % 400 == 0 )
        printf("C'est une année bissextile !");
    else 
        printf("Ce n'est pas une année bissextile");
    return 0;
}


