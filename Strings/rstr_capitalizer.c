/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:19:53 by marvin            #+#    #+#             */
/*   Updated: 2025/03/26 13:19:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void rstr_capitalizer(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z') //on met tout en minuscule
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')) //Si c'est en minuscule et que le caractere d'aprees est un espqce ou ..
            str[i] -= 32; //on met en majuscule
        write (1, &str[i++], 1); //on parcours la chaine   
    }
}

int main (int argc, char **argv)
{
    int i = 1;
    if (argc > 1) //Tant qu'au moins 1 argument est passé
    {
        while (argv[i])
        {
            rstr_capitalizer(argv[i]);
            write (1, "\n", 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}