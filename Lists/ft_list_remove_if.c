#include <stdlib.h> //pour free
#include "ft_list.h"

void    ft_list_remove_if (t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
        return;
    t_list *cur = *begin_list;                // Initialise un pointeur courant au premier élément de la liste
    if (cmp(cur -> data, data_ref) == 0)     // Vérifie si le premier élément est a supprimer
    {
        *begin_list = cur -> next;
        free (cur);                        
        ft_list_remove_if(begin_list, data_ref, cmp); 
    }
    else
    {
        cur = *begin_list;
        ft_list_remove_if (&cur -> next, data_ref, cmp);  // Si le premier élément ne correspond pas, continue vers le nœud suivant
    }
}