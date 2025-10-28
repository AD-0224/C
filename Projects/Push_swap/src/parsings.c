
#include "push_swap.h"

char	**split_arguments(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv + 1;
	}
	return (args);
}

int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	validate_arguments(char **args, int size, int argc)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_number(args[i]))
		{
			if (argc == 2)
				ft_free_tab(args);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	*convert_to_int_array(char **args, int size, int argc)
{
	int		*array;
	int		value;
	int		i;

	array = malloc(sizeof(int) * (size));
	if (!array)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		if (ft_atoi_safe(args[i], &value) == -1)
		{
			if (argc == 2)
				ft_free_tab(args);
			free(array);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		array[i] = value;
		i++;
	}
	return (array);
}

int	*parse_args(int argc, char **argv, int *size)
{
	char	**args;
	int		*array;

	args = split_arguments(argc, argv);
	*size = ft_tab_size(args);
	validate_arguments(args, *size, argc);
	array = convert_to_int_array(args, *size, argc);
	if (has_duplicates(array, *size))
	{
		if (argc == 2)
			ft_free_tab(args);
		free(array);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		ft_free_tab(args);
	return (array);
}
