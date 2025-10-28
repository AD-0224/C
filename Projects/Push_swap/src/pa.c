
#include "push_swap.h"

void	pa(int *a, int *size_a, int *b, int *size_b)
{
	int	i;

	if (*size_b == 0)
		return ;
	i = *size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	(*size_a)++;
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_b)--;
	write(1, "pa\n", 3);
}
