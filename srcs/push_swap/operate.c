#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	insert_bigger_b2(t_stock *stocka, t_stock *stockb, t_main *main, int i)
{
		if (find_biggest(stockb) == 0 || stockb->a[0] > stocka->a[0])
		{
			if (stocka->big > stockb->big)
				while (stockb->big > stocka->a[0])
				{
					rotate(stocka, "ra another one\n");
					i++;
				}
		}
		resolve_last_a(stocka, main);
		push(stockb, stocka, "pa ....\n");
		/*
		*/
		resolve_last_a(stocka, main);
		if (stocka->a[0] > stocka->a[1])
			swap(stocka, "sa after pa ...\n");
}

void	insert_bigger_b(t_stock *stocka, t_stock *stockb, t_main *main)
{
	int		i;

	i = 0;
	find_biggest(stocka);
	find_biggest(stockb);
	if (find_biggest(stockb) == 1 && stockb->size > 1)
	{
		swap(stockb, "sb\n");
		//print_stacks_ps(main);
	}
	if (stockb->big < stocka->big || stocka->size <= 2)
		insert_bigger_b2(stocka, stockb, main, i);
	//print_stacks_ps(main);
}

void	resolve_last_a(t_stock *stocka, t_main *main)
{
	int		size;

	size = stocka->size - 1;
	find_biggest(&main->stockb);
	// a rrr can be added in this function
	// happens when stockb->big is > 1/2 of (B)
	// and a[last] > b->big
	//
	if (find_biggest(&main->stockb) > (int)main->stockb.size / 2 - 1 && main->stockb.size > 2)
	{
		while (find_biggest(&main->stockb) != 0)
			reverse_rotate(&main->stockb, "rrb\n");
		//print_stacks_ps(main);
	}
	//*/
	while (stocka->a[size] < stocka->a[0] && stocka->a[size] > main->stockb.a[0]
			&& stocka->a[size] != stocka->big)
	{
		/*
		if (find_biggest(&main->stockb) > (int)main->stockb.size / 2 - 1
		&& main->stockb.size > 2 && stocka->a[size] > main->stockb.big)
		{
			reverse_rotate(&main->stockb, "");
			reverse_rotate(stocka, "rrr\n");
			print_stacks_ps(main);
		}
		else
		*/
			reverse_rotate(stocka, "rra for last_a\n");
		//print_stacks_ps(main);
	}
	//print_stacks_ps(main);
}

int		check_order(t_stock *stocka, t_stock *stockb, t_main *main)
{
	int	i;
	int	tmp;

	i = 0;
	(void)main;
	//printf("_______________________________ check_order\n");
	find_biggest(stocka);
	while (stocka->a[i] != stocka->big)
	{
		if (stocka->size <= 5 && stack_order(stocka) != 0)
			resolve_less_than_five(stocka, stockb);
		if (stack_order(stocka) == 0)
			break ;
		else if (stocka->a[i] > stocka->a[i + 1])
		{
			tmp = stocka->a[i];
			while (stocka->a[0] != tmp)
				rotate(stocka, "ra of check_order\n");
			if (stocka->a[0] > stocka->a[1] && stockb->a[0] < stockb->a[1])
			{
				swap(stocka, "");
				swap(stockb, "ss\n");
			}
			else if (stocka->a[0] > stocka->a[1])
				swap(stocka, "sa\n");
		}
		i++;
	}
	return (0);
}
