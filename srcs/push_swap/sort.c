#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	resolve_small(t_stock *stocka, t_stock *stockb, t_main *main)
{
printf("_______________________________ resolve_small\n");
	find_median(main, stocka);
	while (stocka->size > 5)
	{
		if (*stocka->a < stocka->median)
			push(stocka, stockb, "pb small\n");
		else	
			rotate(stocka, "ra small\n");
	}
	resolve_less_than_five(stocka, stockb);
	resolve_less_than_five_b(stockb);
	if (stack_order_b(stockb) == 0)
		while (stockb->size > 0)
			push(stockb, stocka, "pa small\n");
	//print_stacks_ps(main);
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

int		solve_quarters(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)main;
	int		div;
	int		i;
	int		size_b;

	div = 0;
	i = 0;
	while (stocka->a[i])
	{
		push_quarters(main, stocka, div);
		//exit (1);
		size_b = stockb->size;
		while (size_b > 0)
		{
			find_smallest(stockb);
			find_biggest(stockb);
			size_b--;
		}
		i++;
		div++;
		if (div == 4)
			break ;
	}
	//printf("_______PRINT FROM solve_quarters\n");
	//print_stacks_ps(main);
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
		printf("malloc failed\n");
	while (i < (int)stock->size)
	{
		arr[i++] = stock->a[j++];
	}
	sort_array(arr, stock->size);
	stock->quarter = arr[quarter_len];
	stock->median = arr[quarter_len * 2];
	stock->three_quarters = arr[quarter_len * 3];
//printf("here's your quarter = %ld, median : %ld, three_quarters : %ld\n", stock->quarter, stock->median, stock->three_quarters);
}
