#include"push_swap.h"

int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	radix_sort(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	size = *size_a;
	max_bits = get_max_bits(size);
	normalize_stack(a, size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((a[0] >> i) & 1)
				ra (a, *size_a);
			else
				pb (a, size_a, b, size_b);
			j++;
		}
		while (*size_b)
			pa(a, size_a, b, size_b);
		i++;
	}
}

int	ft_tabint_size(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int	is_sorted(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	size_a;
	int	size_b;
	int	*array_a;
	int	*array_b;

	array_a = parse_args(ac, av, &size_a);
	array_b = malloc(size_a * sizeof(int));
	size_b = 0;
	if (is_sorted(array_a, size_a) == 1)
	{
		free(array_a);
		free(array_b);
		return (0);
	}
	if (size_a <= 5)
		sort_small_stack(array_a, array_b, size_a, &size_b);
	else
		radix_sort(array_a, array_b, &size_a, &size_b);
	free(array_a);
	free(array_b);
	return (0);
}
