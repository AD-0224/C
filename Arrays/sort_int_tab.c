/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:31:30 by marvin            #+#    #+#             */
/*   Updated: 2025/03/27 09:31:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;

    while (i < (size - 1))
    {
        if (tab[i] > tab [i + 1])
        {
            temp = tab [i];
            tab [i] = tab [i + 1];
            tab [i + 1] = temp;
            i = 0; //pour continuer a parcourir la chaine
        }
        else
            i++; //Si c'est trié
    }
}