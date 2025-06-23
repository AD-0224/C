/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LCM.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:33:27 by marvin            #+#    #+#             */
/*   Updated: 2025/03/25 00:33:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned    int lcm(unsigned int a, unsigned int b) //Lowest Common Multiple
{
    unsigned    int n;

    if (a == 0 || b == 0)
        return(0);
    if (a > b)
        n = a;
    else
        n = b;
    while (1)
    {
        if (n % a == 0 && n % b == 0) 
            return (n);
        n++;
    }
}

// #include <stdio.h>

// unsigned int lcm(unsigned int a, unsigned int b);

// int main() {
//     printf("%u\n", lcm(4, 6));
//     return 0;
// }
