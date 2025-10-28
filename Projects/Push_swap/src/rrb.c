
#include "push_swap.h"

void	rrb(int *b, int size)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = b[size - 1];
	i = size - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write (1, "rrb\n", 4);
}
