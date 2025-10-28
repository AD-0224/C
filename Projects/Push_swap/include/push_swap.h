
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

void	pa(int *a, int *size_a, int *b, int *size_b);
void	pb(int *a, int *size_a, int *b, int *size_b);
void	ra(int *a, int size);
void	rb(int *b, int size);
void	rr(int *a, int size_a, int *b, int size_b);
void	rra(int *a, int size);
void	rrb(int *b, int size);
void	rrr(int *a, int size_a, int *b, int size_b);
void	sa(int *a, int size);
void	sb(int *b, int size);
void	ss(int *a, int *b, int size_a, int size_b);
int		find_min_index(int *a, int size);
int		get_max_bits(int size);
void	sort_two(int *a, int size);
void	sort_three(int *a, int size);
void	sort_four(int *a, int *b, int *size_a, int *size_b);
void	sort_five(int *a, int *b, int *size_a, int *size_b);
void	move_min_to_top(int *a, int size, int min_index);
void	radix_sort(int *a, int *b, int *size_a, int *size_b);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	count_word(char const *s, char c);
void	fill_tab(char *new, char const *s, char c);
void	set_mem(char **tab, char const *s, char c);
void	sort_small_stack(int *a, int *b, int size_a, int *size_b);
void	insert_b_into_a(int *a, int *size_a, int *b, int *size_b);
int		get_move_cost(int index, int size);
int		find_best_move(int *a, int size_a, int *b, int size_b);
void	execute_best_move(int *a, int *size_a, int *b, int *size_b);
void	push_half_to_b(int *a, int *size_a, int *b, int *size_b);
int		find_insert_position(int *b, int size_b, int value);
int		get_median(int *arr, int size);
int		get_min_rotation_cost(int *a, int size_a, int *b, int size_b);
void	rotate_stacks(int *a, int size_a, int *b, int size_b);
int		is_number(const char *str);
int		has_duplicates(int *a, int size);
int		is_sorted(int *a, int size);
int		ft_atoi_safe(const char *str, int *out);
void	exit_error(void);
void	ft_free_tab(char **tab);
void	normalize_stack(int *a, int size);
void	replace_with_index(int *a, int *sorted, int size);
void	sort_array(int *arr, int size);
int		*copy_stack(int *a, int size);
char	**split_arguments(int argc, char **argv);
void	validate_arguments(char **args, int size, int argc);
int		*convert_to_int_array(char **args, int size, int argc);
int		ft_tab_size(char **tab);
int		*parse_args(int argc, char **argv, int *size);

#endif
