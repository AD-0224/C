/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:20:13 by marvin            #+#    #+#             */
/*   Updated: 2025/03/27 00:20:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void   ft_list_foreach(t_list *begin_list, void(*f) (void*))
{
    while (begin_list)
    {
        (*f)(begin_list -> data); //Applique la fonction a l'element actuel 
        begin_list = begin_list -> next; //passe a l'element suivant 
    }
}