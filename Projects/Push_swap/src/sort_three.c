#include "push_swap.h"

void	sort_three(int *a, int size)
{
	if (size != 3)
		return ;
	if (a[0] > a[1] && a[0] > a[2])
		ra (a, size);
	if (a[1] > a[0] && a[1] > a[2])
		rra (a, size);
	if (a[0] > a[1])
		sa (a, size);
}
