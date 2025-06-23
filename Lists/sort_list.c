/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:05:28 by marvin            #+#    #+#             */
/*   Updated: 2025/03/27 10:05:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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