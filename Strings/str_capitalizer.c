/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:50:10 by marvin            #+#    #+#             */
/*   Updated: 2025/03/26 13:50:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    str_capitalizer(char *str)
{
    int i = 0;

    if (str[i] >= 'a' && str[i] <= 'z') //lettre du debut puisque il ya ni espace si tabulation
        str[i] -= 32;
    write (1, &str[i], 1);
    i++;
    
    while (str[i]) //Pour ceux d'apres
    {
        if (str[i] >= 'A' && str[i] <= 'Z') 
            str[i] += 32; //minuscule
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t')) //si c'est une minuscule et que le caractere d'avant etait un espace ou un tab tu mets en majuscule 
            str[i] -= 32; //tu mets en majuscule
        write (1, &str[i], 1);
        i++;
    }
}
int main (int argc, char **argv)
{
    int i;
    if (argc > 1)
    {
        i = 1; //on commence au premier argument
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}