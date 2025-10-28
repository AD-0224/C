
#include "push_swap.h"

void	sa(int *a, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write (1, "sa\n", 3);
}
