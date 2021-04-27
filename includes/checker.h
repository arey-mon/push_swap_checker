/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:56:47 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/27 12:32:11 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_stock
{
	int		*a;
	size_t	size;
	int		big;
	int		small;
	int		write;
	long	quarter;
	long	median;
	long	three_quarters;
	long	first_long;
	long	second_long;
	long	third_long;
	long	fourth_long;
	long	median_long;
	long	six_long;
	long	seven_long;
	long	eight_long;
	long	nine_long;
}				t_stock;

typedef struct	s_pgm
{
	t_stock			stocka;
	t_stock			stockb;
}				t_pgm;

/*
 **  PROGRAM (PUSH_SWAP)
*/
int				check_order(t_stock *stocka, t_stock *stockb, t_pgm *pgm);
int				new_check_order(t_stock *stocka);
void			find_median(t_stock *stock);
void			find_median_ten(t_stock *stock);
void			find_moves(t_stock *stocka, t_stock *stockb, t_pgm *pgm);
void			push_long(t_pgm *pgm, t_stock *stocka, int div, int last_a);
void			push_quarters(t_pgm *pgm, t_stock *stocka, int div);
void			push_first_long(t_pgm *pgm);
void			push_second_long(t_pgm *pgm);
void			push_third_long(t_pgm *pgm);
void			push_fourth_long(t_pgm *pgm);
void			push_median_long(t_pgm *pgm);
void			push_six_long(t_pgm *pgm);
void			push_seven_long(t_pgm *pgm);
void			push_eight_long(t_pgm *pgm);
void			push_nine_long(t_pgm *pgm);
void			push_first_quarter(t_pgm *pgm);
void			push_second_quarter(t_pgm *pgm);
void			push_third_quarter(t_pgm *pgm);
void			push_fourth_quarter(t_pgm *pgm);
void			resolve_last_a(t_stock *stocka, t_pgm *pgm);
void			resolve_small(t_stock *stocka, t_stock *stockb);
int				resolve_three(t_stock *stocka);
int				resolve_four_b(t_stock *stocka);
int				resolve_five(t_stock *stocka, t_stock *stockb);
int				resolve_less_than_five(t_stock *stocka, t_stock *stockb);
int				resolve_less_than_five_b(t_stock *stockb);
int				solve_quarters(t_stock *stocka, t_pgm *pgm);
int				solve_ten(t_stock *stocka, t_pgm *pgm);
int				find_biggest(t_stock *stock);
int				find_smallest(t_stock *stock);
void			get_malloc_size(t_stock *stocka, t_pgm *pgm);
int				stack_order_ps(t_stock *stock);
int				stack_order_b(t_stock *stock);
/*
 **  PROGRAM (CHECKER && SHARED)
*/
int				check_duplicates(t_stock *stock);
int				check_instructions(char *line, t_stock *stocka,
		t_stock *stockb);
void			execute_instructions(char *line, t_stock *stocka,
		t_stock *stockb);
int				ft_iswhitespace(char a);
int				fill_stack(int ac, char **arg, t_stock *stock);
int				ft_atoi_int(char *str, int *num);
char			*ft_strdup_char(const char *str, char stop);
int				ft_strlen_int(int *size);
int				get_args_size(char **av, int ac);
int				init_stock(t_stock *stocka, t_stock *stockb, char **arg,
		int ac);
int				integers_check(char *str);
int				integers_check_pos(char *str);
int				integers_check_neg(char *str);
int				read_instructions(t_stock *stocka, t_stock *stockb, int ret,
		int err);
int				read_instructions2(t_stock *stocka, int ret, int err);
int				split_args(char *fill, t_stock *stock, int i);
int				stack_order(t_stock *stock, int err);
/*
 ** Functions_set
*/
int				push(t_stock *stock, t_stock *dest, char *str);
void			erase(t_stock *stack, size_t index);
void			rotate(t_stock *stock, char *str);
void			reverse_rotate(t_stock *stock, char *str);
void			swap(t_stock *stocka, char *str);
#endif
