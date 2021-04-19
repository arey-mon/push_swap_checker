#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void		resolve_small(t_stock *stocka, t_stock *stockb, t_main *main)
{
	find_median(main, stocka);
	while (stocka->size > 5)
	{
		if (*stocka->a < stocka->median)
			push(stocka, stockb, "pb\n");
		else
			rotate(stocka, "ra\n");
	}
	resolve_less_than_five(stocka, stockb);
	resolve_less_than_five_b(stockb);
	if (stack_order_b(stockb) == 0)
		while (stockb->size > 0)
			push(stockb, stocka, "pa\n");
}

static void	sort_array(int *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

void	find_median_ten(t_main *main, t_stock *stock)
{
	//printf("_______________________________ FIND_MEDIAN\n");
	int		tenth;
	int		*arr;
	int		i;
	int		j;
	(void)main;

	i = 0;
	j = 0;
	tenth = stock->size / 10;
	if (!(arr = (int*)malloc(sizeof(int) * (stock->size + 1))))
		exit (1);
	while (i < (int)stock->size)
	{
		arr[i++] = stock->a[j++];
	}
	sort_array(arr, stock->size);
	stock->first_long = arr[tenth];
	stock->second_long = arr[tenth * 2];
	stock->third_long = arr[tenth * 3];
	stock->fourth_long = arr[tenth * 4];
	stock->median_long = arr[tenth * 5];
	stock->six_long = arr[tenth * 6];
	stock->seven_long = arr[tenth * 7];
	stock->eight_long = arr[tenth * 8];
	stock->eight_long = arr[tenth * 9];
}

int		solve_ten(t_stock *stocka, t_main *main)
{
	(void)main;
	int		div;
	int		i;

	div = 0;
	i = 0;
	while (stocka->a[i])
	{
		push_long(main, stocka, div);
		if (div == 9)
			break ;
		i++;
		div++;
	}
	//printf("_______PRINT FROM solve_ten\n");
	//print_stacks_ps(main);
	return (0);
}

int		solve_quarters(t_stock *stocka, t_main *main)
{
	(void)main;
	int		div;
	int		i;

	div = 0;
	i = 0;
	while (stocka->a[i])
	{
		push_quarters(main, stocka, div);
		if (div == 4)
			break ;
		i++;
		div++;
	}
	return (0);
}

void	find_median(t_main *main, t_stock *stock)
{
	//printf("_______________________________ FIND_MEDIAN\n");
	int		quarter_len;
	int		*arr;
	int		i;
	int		j;
	(void)main;

	i = 0;
	j = 0;
	quarter_len = stock->size / 4;

	if (!(arr = (int*)malloc(sizeof(int) * (stock->size + 1))))
		exit (1);
	while (i < (int)stock->size)
	{
		arr[i++] = stock->a[j++];
	}
	sort_array(arr, stock->size);
	stock->quarter = arr[quarter_len];
	stock->median = arr[quarter_len * 2];
	stock->three_quarters = arr[quarter_len * 3];
}
