
#include "push_swap.h"

void	ra(int *a, int size)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = temp;
	write (1, "ra\n", 3);
}
