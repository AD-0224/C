/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:56:56 by marvin            #+#    #+#             */
/*   Updated: 2025/03/25 00:56:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range (int start, int end)
{
    int i = 0;
    int len;
    int *res;

    //calcule la taille du tableau
    if (start <= end) //ordre croissant
        len = end - start + 1;
    else 
        len = start - end + 1; //ordre decroissant
    //allocation de memoire
    res = (int *)malloc(sizeof(int) * len);
    if (!res)
        return (NULL);
    //remplissage
    while (i < len)
    {
        if (start < end) //croissant on fait dans l'ordre
        {
            res[i] = start;
            start++;
            i++;
        }
        else //decroissant on remplit dans l'ordre inverse
        {
            res[i] = start;
            start--;
            i++;
        }
    }
    return (res);
}

// #include<stdio.h>
// int main (int argc, char **argv)
// {
//     int *tab = ft_range(-1, 2);
//     printf("%d", tab[0]);
//     return (0);
// }