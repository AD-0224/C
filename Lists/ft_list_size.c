/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:31:47 by marvin            #+#    #+#             */
/*   Updated: 2025/03/26 15:31:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    if (begin_list == 0)
        return (0);
    else 
        return (1 + ft_list_size(begin_list -> next)); //elle ajoute 1 a chaque fois quelle rencontre un element jusqu'a NULL, et retourne la taille
}