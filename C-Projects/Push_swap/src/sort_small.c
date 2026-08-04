#include "push_swap.h"

void	sort_small_stack(int *a, int *b, int size_a, int *size_b)
{
	if (size_a == 2)
		sort_two(a, size_a);
	else if (size_a == 3)
		sort_three(a, size_a);
	else if (size_a == 4)
		sort_four(a, b, &size_a, size_b);
	else if (size_a == 5)
		sort_five(a, b, &size_a, size_b);
}
