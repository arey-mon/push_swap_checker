#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int		insertion_diff(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)stockb;
	(void)stocka;
	(void)main;
	int	i;
	int	b_size;
	int	diff_up;
	int	diff_down;
	int	res;

	i = 0;
	diff_up = 0;
	diff_down = 0;
	b_size = stockb->size - 1;
	// PRE-PUSH
	//printf("stocka->a[i] that you're gonna push : %d\n", stocka->a[i]);
	//printf("your first_b = %d && your last_b = %d\n", stockb->a[i], stockb->a[b_size]);
	if (stocka->a[0] > stockb->a[0])
		diff_up = 0;
	else if (stocka->a[0] < stockb->a[0])
		diff_up = stockb->a[0] - stocka->a[0];
	//printf("diff_up gives you %d\n", diff_up);
	if (stocka->a[0] > stockb->a[b_size])
		diff_down = stocka->a[0] - stockb->a[b_size];
	else if (stocka->a[0] < stockb->a[0])
		diff_up = 0;
	//printf("diff_down gives you %d\n", diff_down);
	res = (diff_up > diff_down) ? 0 : 1;
	//printf("your res = %d\n", res);
	//print_stacks_ps(main);
	return (res);
}

int		select_pivot(int div, t_main *main)
{
	int	pivot;

	pivot = 0;
	find_biggest(&main->stockb);
	if (div == 0)
		pivot = main->stocka.quarter;
	else if (div == 1)
		pivot = main->stocka.median;
	else if (div == 2)
		pivot = main->stocka.three_quarters;
	else if (div == 3) // it is an else here, should resolve itself
		pivot = main->stockb.big;
	return (pivot);
}

int		push_check(t_stock *stocka, int div, t_main *main)
{
	int	pivot;
	int	off;
	int	i;
	int	last_a;

	i = 0;
	off = 1;
	pivot = select_pivot(div, main);
	last_a = stocka->a[stocka->size - 1];
	while (stocka->a[i] != last_a)
	{
		if (stocka->a[i] <= pivot)
		{
			off = 0;
			break ;
		}
		i++;
	}
	return (off);
}

int		choose_rotation(t_stock *stocka, int div, t_main *main)
{
	int	i;
	int	count_inc;
	int	count_dec;
	int	size;
	int	pivot;

	stocka->moves = 0;
	pivot = select_pivot(div, main);
	i = 0;
	count_inc = 1;
	count_dec = 1;
	size = stocka->size - 1;
	while (size)
	{
		if (stocka->a[i] <= pivot)
		{
			count_inc = i;
			break ;
		}
		i++;
		size--;
	}
	i = stocka->size - 1;
	while (i > 0)
	{
		if (stocka->a[i] < pivot)
			break ;
		i--;
		size++;
		count_dec++;
	}
	stocka->moves = (count_inc <= count_dec) ? count_inc : count_dec;
	return (count_inc <= count_dec) ? 1 : 0;
}

/*
int		get_pivot(t_stock *stocka, t_main *main)
{
	(void)main;

	find_smallest(stocka);
	find_biggest(stocka);
	stocka->pivot = (stocka->big + stocka->small) / 2;
	printf("ending adjust_pivot with\npivot = %d\n", stocka->pivot);
	return (0);
}
*/
