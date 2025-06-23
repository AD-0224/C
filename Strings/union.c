/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidahdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:12:56 by aidahdou          #+#    #+#             */
/*   Updated: 2025/03/27 15:23:45 by aidahdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//afficher une chaine sans les doubles

#include <unistd.h>

int     main(int argc, char **argv)
{
        int     i;
        int     j;
        unsigned char seen[256] = {0};  // Tableau pour suivre les caractères déjà vus (256 pour couvrir tous les caractères ASCII).
        if (argc == 3)
        {
			i = 0;
        	while(argv[1][i])
        	{
				if (!seen[(unsigned char) argv[1][i]]) //numero dans la table ascii
				{
					write(1, &argv[1][i], 1);
					seen [(unsigned char)argv[1][i]] = 1;
        	  	}
           		i++;
			}
			j = 0;
			while (argv[2][j])
			{
				if(!seen[(unsigned char) argv[2][j]])
          		{
					write(1, &argv[2][j], 1);
             		seen [(unsigned char)argv[2][j]] = 1;
       			}
           		j++;
			}
		}
		write(1,"\n", 1);
		return (0);
}
