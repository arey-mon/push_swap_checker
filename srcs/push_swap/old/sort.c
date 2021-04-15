#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int		small_to_b(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)main;
	//printf("_________PRINT FROM SMALL TO B\n");
	//print_stacks_ps(main);
	while (find_smallest(stocka) == 0)
		push(stocka, stockb, "pb\n");
	if (stockb->size <= 4)
		resolve_less_than_five_b(stockb);
	return (0);
}

int		sort_b(t_stock *stocka, t_stock *stockb, t_main *main)
{
	//printf("___________________________\n");
	small_to_b(stocka, stockb, main);
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, stockb);
	if (stack_order(stocka) == 0)
	{
		while (find_biggest(stockb) == 0)
			push(stockb, stocka, "pa\n");
		resolve_less_than_five_b(stockb);
		while (find_biggest(stockb) == 0)
			push(stockb, stocka, "pa\n");
	}
	return (0);
}

int		sort_a(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)main;
	(void)stockb;
	//printf("______________________________ SORT_A\n");
	while (stack_order(stocka) != 0)
	{
		if (stocka->size <= 5)
			break ;
		small_to_b(stocka, stockb, main);
		if (stocka->a[0] > stocka->a[1])
			swap(stocka, "sa\n");
		else
			reverse_rotate(stocka, "rra\n");
	}
	resolve_less_than_five(stocka, stockb);
	while (find_biggest(stockb) == 0)
		push(stockb, stocka, "pa\n");
	//print_stacks_ps(main);
	return (0);
}

int		insert_tmp_val_b(t_stock *stockb, t_stock *stocka, int i, t_main *main)
{
	//printf("_________________________________TMP_VAL_B\n");
	int	tmp_val;
	(void)stocka;
	(void)main;

	tmp_val = stockb->a[i];
	//printf("your tmp_val is : %d\n", tmp_val);
	//print_stacks_ps(main);
	//printf("your stockb->big is : %d\n", stockb->big);
	if (i < (int)stockb->size / 2)
	{
		find_biggest(stockb);
		while (stockb->a[0] != stockb->big)
			reverse_rotate(stockb, "rrb\n");
		push(stockb, stocka, "pa\n");
	}
	else
	{
		find_biggest(stockb);
		while (stockb->a[0] != stockb->big)
			rotate(stockb, "rb\n");
		//print_stacks_ps(main);
		push(stockb, stocka, "pa\n");
	}
	//printf("_________________________________>>>>>>TMP_VAL_B\n");
	return (0);
}

int		resolve_b(t_stock *stockb, t_stock *stocka, t_main *main)
{
	int	i;
	(void)stocka;

	//printf("_________________________________ RESOLVE_B\n");
	//print_stacks_ps(main);
	get_pivot(stockb, main);
	while (stack_order_b(stockb) != 0)
	{
		i = 0;
		while (stocka->a[i])
		{
			//print_stacks_ps(main);
			//printf("a[i] is : %d, i is : %d\n", stockb->a[i], i);
			if (find_biggest(stockb) == 0)
				push(stockb, stocka, "pa\n");
			if (stockb->size <= 4)
				resolve_less_than_five_b(stockb);
			if (stockb->a[1] > stockb->a[0])
			{
				//printf("IF1\n");
				swap(stockb, "sb\n");
			}
			if (stockb->a[i] > stockb->a[i - 1] && i > 0)
			{
				insert_tmp_val_b(stockb, stocka, i, main);
				break ;
			}
			i++;
		}
	}
	return (0);
}

int		sort(t_stock *stocka, t_stock *stockb, t_main *main)
{
	if (stack_order_b(stockb) != 0)
		sort_b(stocka, stockb, main);
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, stockb);
	else if (stack_order(stocka) != 0)
		sort_a(stocka, stockb, main);
	if (stack_order_b(stockb) != 0)
		resolve_b(stockb, stocka, main);
	return (stack_order(stocka) == 0) ? 0 : 1;
}
