#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int temp;
    t_list *start = lst;

    while (lst != NULL && lst -> next != NULL)
    {
        if ((*cmp)(lst -> data, lst -> next -> data) == 0) //pas trie
        {
            temp = lst -> data;
            lst -> data = lst -> next -> data;
            lst -> next -> data = temp;
            lst = start;  // on repart du début pour vérifier tout à nouveau
        }
        else 
            lst = lst -> next; //si elle est trie on continue a parcourir la chaine
    }
    return (start);
}