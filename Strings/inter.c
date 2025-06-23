/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidahdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:26:25 by aidahdou          #+#    #+#             */
/*   Updated: 2025/03/27 15:12:17 by aidahdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ce qui a dans les 2

#include <unistd.h>

int	main (int argc, char **argv) //afficher une chaine dans l'ordre sans les doubles 
{
	int	i;
	int	j;
	unsigned char seen[256] = {0};
	if (argc == 3)
	{
		i = 0;
		while(argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j]) //si ils sont identiques
				{
					if (!seen[(unsigned char) argv[1][i]]) //Si on l'avait pas deja vu on le met comme vu
					{
						write(1, &argv[1][i], 1);
						seen [(unsigned char)argv[1][i]] = 1;
					}
					break; 
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
