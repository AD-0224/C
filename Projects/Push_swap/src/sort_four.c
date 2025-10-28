
#include "push_swap.h"

int	find_min_index(int *a, int size)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (a[i] < a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	move_min_to_top(int *a, int size, int min_index)
{
	while (min_index > 0)
	{
		ra(a, size);
		min_index--;
	}
}

void	sort_four(int *a, int *b, int *size_a, int *size_b)
{
	int	min_index;

	min_index = find_min_index(a, *size_a);
	move_min_to_top(a, *size_a, min_index);
	pb(a, size_a, b, size_b);
	sort_three(a, *size_a);
	pa(a, size_a, b, size_b);
}
