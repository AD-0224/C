
#include "push_swap.h"

void	rrr(int *a, int size_a, int *b, int size_b)
{
	if (size_a > 1)
		rra(a, size_a);
	if (size_b > 1)
		rrb(b, size_b);
	write (1, "rrr\n", 4);
}
