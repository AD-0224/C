
#include "push_swap.h"

void	rb(int *b, int size)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = b[0];
	i = 0;
	while (i < size - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size - 1] = temp;
	write (1, "ra\n", 3);
}
