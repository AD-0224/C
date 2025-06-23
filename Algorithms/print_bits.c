/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits 2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:58:50 by aidahdou          #+#    #+#             */
/*   Updated: 2025/04/23 16:51:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	while (i--)
	{
		if (octet & (1 << i)) // Vérifie si le bit à la position i est à 1.
			write (1, "1", 1);
		else
			write (1, "0", 1);
	}
}
