
#include "push_swap.h"

void	sb(int *b, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write (1, "sb\n", 3);
}
