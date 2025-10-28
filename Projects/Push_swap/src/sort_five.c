
#include "push_swap.h"

void	sort_five(int *a, int *b, int *size_a, int *size_b)
{
	int	min_index;

	min_index = find_min_index(a, *size_a);
	move_min_to_top(a, *size_a, min_index);
	pb (a, size_a, b, size_b);
	min_index = find_min_index(a, *size_a);
	move_min_to_top(a, *size_a, min_index);
	pb(a, size_a, b, size_b);
	sort_three(a, *size_a);
	pa(a, size_a, b, size_b);
	pa(a, size_a, b, size_b);
}
