/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:50:05 by marvin            #+#    #+#             */
/*   Updated: 2025/03/27 09:50:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// imprime la chaine, a l'envers en conservant l'ordre des mots

#include <unistd.h>

void	rev_wstr(char *str)
{
	int i = 0;
	int start;

	while (str[i] == ' ' || str[i] == '\t') //on ignore ceux du début
		i++;
	if (str[i] == '\0')
		return;
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	rev_wstr(str + i);
	if (str[i])
		write(1, " ", 1);
	write(1, str + start, i - start);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}

