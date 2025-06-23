/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidahdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:27:21 by aidahdou          #+#    #+#             */
/*   Updated: 2025/03/21 11:48:54 by aidahdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_number(int number)
{
	char str[10] = "0123456789"; //Mapping str[2] = '2'
	if (number > 9)
		ft_write_number(number / 10); //recursion
	write (1, &str[number % 10], 1); //donne le dernier chiffre
}

int main ()
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else
			ft_write_number(i);
		i++;
		write(1, "\n", 1);
	}
}