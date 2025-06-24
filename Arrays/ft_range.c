#include <stdlib.h>

int *ft_range (int start, int end)
{
    int i = 0;
    int len;
    int *res;

    if (start <= end)
        len = end - start + 1;
    else 
        len = start - end + 1;
    res = (int *)malloc(sizeof(int) * len);
    if (!res)
        return (NULL);
    while (i < len)
    {
        if (start < end)
        {
            res[i] = start;
            start++;
            i++;
        }
        else
        {
            res[i] = start;
            start--;
            i++;
        }
    }
    return (res);
}

// #include<stdio.h>
// int main (int argc, char **argv)
// {
//     int *tab = ft_range(-1, 2);
//     printf("%d", tab[0]);
//     return (0);
// }