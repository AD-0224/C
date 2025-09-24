#include <stdlib.h>
#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int temp;
    t_list *start = lst;

    while (lst != NULL && lst -> next != NULL)
    {
        if ((*cmp)(lst -> data, lst -> next -> data) == 0) //Not sort
        {
            temp = lst -> data;
            lst -> data = lst -> next -> data;
            lst -> next -> data = temp;
            lst = start;
        }
        else 
            lst = lst -> next;
    }
    return (start);
}