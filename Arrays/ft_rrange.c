#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *res;
    int len;
    int i = 0; 

    if (start <= end) 
        len = end - start + 1; 
    else 
        len = start - end + 1;
    res = (int *)malloc(sizeof(int) * len);
    if (!res)
        return(NULL);
    while (i < len)
    {
        if (start <= end) //ordre croissant
            res[i] = end - i; //9876
        else
            res[i] = end + i; //6789
        i++;
    }
    return (res);
}
// #include <stdio.h>

// int main (void)
// {
//     int *tab = ft_rrange(1,3);
//     printf("%d", tab[2]);
//     return (0);
// }
