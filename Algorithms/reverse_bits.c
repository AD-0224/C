/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidahdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:11:24 by aidahdou          #+#    #+#             */
/*   Updated: 2025/03/21 15:15:03 by aidahdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bit(unsigned char octet)
{
	int	i = 8;
	unsigned char result = 0;
	while (i--)
	{
		result = (result << 1) | (octet & 1); 
		octet >>= 1; // Décale octet à droite pour traiter le bit suivant.
	}
	return (result);
}
