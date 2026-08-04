#include "push_swap.h"

void	rra(int *a, int size)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = a[size - 1];
	i = size - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	write (1, "rra\n", 4);
}
