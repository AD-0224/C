#include <stdlib.h>
#include "ft_list.h"

void    ft_list_remove_if (t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
        return;
    t_list *cur = *begin_list;                //Initializes a current pointer to the first element of the list
    if (cmp(cur -> data, data_ref) == 0)     //Check if the first element is to be deleted
    {
        *begin_list = cur -> next;
        free (cur);                        
        ft_list_remove_if(begin_list, data_ref, cmp); 
    }
    else
    {
        cur = *begin_list;
        ft_list_remove_if (&cur -> next, data_ref, cmp);  //If the first element does not match, continue to the next node
    }
}