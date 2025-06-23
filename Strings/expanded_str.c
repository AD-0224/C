/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanded_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:57:46 by marvin            #+#    #+#             */
/*   Updated: 2025/03/26 16:57:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char const **argv)
{
    int i;
    int flg;

    if (argc == 2)
    {
        i = 0;
        flg = 0;
        while (argv [1][i] == ' ' || argv [1][i] == '\t') //on ignore ceux du debut pour par les re ecrire 
            i++;
        while (argv [1][i])
        {
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flg = 1;
            else
            {
                if (flg)
                write (1, "   ", 3);
                flg = 0;
                write (1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}