#ifndef CHECKER_H
# define CHECKER_H

# define BIG_FLAG 0
# define SMALL_FLAG 0

# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_stock
{
	int		*a;
	size_t	size;
	int		big;
	int		small;
	int		write;
	int		pivot;
	int		moves;
	long			quarter;
	long			median;
	long			three_quarters;
}				t_stock;

typedef struct	s_main
{
	t_stock			stocka;
	t_stock			stockb;
	int				small_flag;
	int				big_flag;
}				t_main;

/*
**  PROGRAM (PUSH_SWAP)
*/
int		adjust_pivot(size_t count, size_t size_b, t_stock *stocka);
int		choose_rotation(t_stock *stocka, int div, t_main *main);
int		create_stock(t_stock *stocka, t_main *main);
void	divide_stock(t_stock *stocka, t_stock *stockb, t_main *main);
int		insertion_diff(t_stock *stocka, t_stock *stockb, t_main *main);
void	find_median(t_main *main, t_stock *stock);
void	find_moves(t_stock *stocka, t_stock *stockb, t_main *main);
//int		get_pivot(t_stock *stocka, t_main *main);
int		push_check(t_stock *stocka, int div, t_main *main);
void	push_quarters(t_main *main, t_stock *stocka, int div);
void	push_first_quarter(t_main *main);
void	push_second_quarter(t_main *main);
void	push_third_quarter(t_main *main);
void	push_fourth_quarter(t_main *main);
void	reset_moves(t_stock *stock);
void	resolve_last_a(t_stock *stocka, t_main *main);
void	resolve_small(t_stock *stocka, t_stock *stockb, t_main *main);
int		resolve_three(t_stock *stocka);
int		resolve_four_b(t_stock *stocka);
int		resolve_five(t_stock *stocka, t_stock *stockb);
int		resolve_less_than_five(t_stock *stocka, t_stock *stockb);
int		resolve_less_than_five_b(t_stock *stockb);
int		solve_quarters(t_stock *stocka, t_stock *stockb, t_main *main);
int		sort(t_stock *stocka, t_stock *stockb, t_main *main);
int		sort(t_stock *stocka, t_stock *stockb, t_main *main);
int		find_biggest(t_stock *stock);
int		find_smallest(t_stock *stock);
void	get_malloc_size(t_stock *stocka, t_main *main);
void	get_nb_of_stocks(t_stock *stocka, t_main *main);
int		stack_order_b(t_stock *stock);
/*
**  PROGRAM (CHECKER && SHARED)
*/
int		check_duplicates(t_stock *stock);
int		check_instructions(char *line, t_stock *stocka, t_stock *stockb);
void	execute_instructions(char *line, t_stock *stocka, t_stock *stockb);
int		ft_iswhitespace(char a);
int		fill_stack(int ac, char **arg, t_stock *stock);
int		ft_atoi_int(char *str, int *num);
int		ft_strlen_int(int *size);
int		get_args_size(char **av, int ac);
int		init_stock(t_stock *stocka, t_stock *stockb, char **arg, int ac);
int		integers_check(char *str);
int		integers_check_pos(char *str);
int		integers_check_neg(char *str);
int		read_instructions(t_stock *stocka, t_stock *stockb);
int		read_instructions2(t_stock *stocka, int ret);
int		split_args(char *fill, t_stock *stock, int i);
int		stack_order(t_stock *stock);
/*
** Functions_set
*/
int		push(t_stock *stock, t_stock *dest, char *str);
void	erase(t_stock *stack, size_t index);
void	rotate(t_stock *stock, char *str);
void	reverse_rotate(t_stock *stock, char *str);
void	swap(t_stock *stocka, char *str);
/*
** HELPING
*/
void	functions_test();
void	print_stacks(t_stock *stocka, t_stock *stockb);
void	print_stacks_ps(t_main *main);
#endif
