#include "push_swap.h"

void	rr(int *a, int size_a, int *b, int size_b)
{
	if (size_a > 1)
		ra (a, size_a);
	if (size_b > 1)
		rb (b, size_b);
	write(1, "rr\n", 3);
}
