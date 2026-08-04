#include "push_swap.h"

int	*copy_stack(int *a, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < size)
		copy[i] = a[i];
	return (copy);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void	replace_with_index(int *a, int *sorted, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (sorted[j] != a[i])
			j++;
		a[i] = j;
	}
}

void	normalize_stack(int *a, int size)
{
	int	*sorted;

	sorted = copy_stack(a, size);
	if (!sorted)
		return ;
	sort_array(sorted, size);
	replace_with_index(a, sorted, size);
	free(sorted);
}
