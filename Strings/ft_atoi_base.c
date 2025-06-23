/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:40:38 by marvin            #+#    #+#             */
/*   Updated: 2025/03/26 10:40:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(const char *str, int str_base)
{
    int res = 0; //resultat
    int sign = 1; //pour géré les signes
    int i = 0; //index
    int    c; // Valeur numérique du caractère actuel

    if (!str || str_base < 2 || str_base > 16 ) //limite si la chaine n'est pas dans la base
        return 0;
    if (*str == '-')
    {
        sign = - 1;
        str++;
    }
    while(str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            c = str[i] - '0';                       //conversion des chiffres en ASCII
        else if (str[i] >= 'a' && str[i] <= 'f')
            c = str[i] - 'a' + 10;                  // Convertit la lettre en sa valeur numérique (10-15)
        else if (str[i] >= 'A' && str[i] <= 'F')
            c = str[i] - 'A' + 10;
        else
            break;
        if (c >= str_base)
            break;
        res = res * str_base + c;
        i++;
    }
    return (res * sign);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("Test: %d\n", ft_atoi_base("101", 2));
// }