/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:46:28 by marvin            #+#    #+#             */
/*   Updated: 2025/03/25 22:46:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//Si on trouve la premiere dans la seconde 

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while (argv[2][j] && argv[1][i]) //si elles ne sont pas finis
        {
            if (argv[2][j] == argv[1][i]) //si on trouve le meme caractere
                i++;
            j++;
        }
        if (argv[1][i] == '\0') //si on a tout parcouru
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}