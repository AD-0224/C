/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev 2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:22:59 by aidahdou          #+#    #+#             */
/*   Updated: 2025/05/04 17:51:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrev(char *str)
{
	int	i = 0;
	int	len = 0;
	char	temp;

	if (!str)
		return (0); //Si elle est nulle
	while (str[len])
		len++; //Compteur
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];  // Remplace le caractère à la position i par celui de la fin
		str[len - 1 - i] = temp;// Place l'ancien caractère à la fin
		i++;
	}
	return (str);
}
