#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	insert_bigger_b(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)main;
	//printf("_______________________________ insert_bigger_b\n");
	find_biggest(stocka);
	find_biggest(stockb);
	if (find_biggest(stockb) == 1 && stockb->size > 1)
		swap(stockb, "sb\n");
	if (stockb->big < stocka->big || stocka->size <= 2)
	{
		// does this really happen ?
		if (stocka->size < 2 && stockb->big > stocka->big)
		{
			push(stockb, stocka, "pa .!!.\n");
			swap(stocka, "sa this\n");
		}
		int i = 0;
		if (find_biggest(stockb) == 0 || stockb->a[0] > stocka->a[0])
		{
			if (stocka->big > stockb->big)
			{
				while (stockb->big > stocka->a[0])
				{
					//resolve_last_a(stocka, main);
					rotate(stocka, "ra another one\n");
					i++;
				}
			}
			else
			{

			}
		}
		resolve_last_a(stocka, main);
		//print_stacks_ps(main);
		// THAT ONE COSTS ME LOT OF MOVES FOR ONE INSERTION
		push(stockb, stocka, "pa ....\n");
		//printf("print after push, then going to resolve_last_a\n");
		//print_stacks_ps(main);
		// ADDED after && so you don't reverse when last_a > b->big
		while (i-- > 1 && stocka->a[stocka->size - 1] > stockb->big)
		{
			find_biggest(stockb);
			if (stocka->a[stocka->size - 1] < stockb->a[0] && stockb->a[0] == stockb->big)
			{
				push(stockb, stocka, "pa resolve ??\n");
				break ;
			}
			reverse_rotate(stocka, "rra try !!! \n");
		}
		resolve_last_a(stocka, main);
		if (stocka->a[0] > stocka->a[1])
			swap(stocka, "sa after pa ...\n");
	}
	//print_stacks_ps(main);
}

int		do_first_operation(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)stocka;
	(void)main;
	find_biggest(stockb);
	insert_bigger_b(stocka, stockb, main);
	return (0);
}

int		exceptions_deal(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)stocka;
	(void)main;
	//printf("____________ EXCEPTIONS_DEAL\n");
	if (stockb->size <= 4)
		resolve_less_than_five_b(stockb);
	return (0);
}

void	resolve_last_a(t_stock *stocka, t_main *main)
{
	//printf("_______________________________ resolve_last_a\n");
	//print_stacks_ps(main);
	int		size;

	size = stocka->size - 1;
	find_biggest(&main->stockb);
	while (stocka->a[size] < stocka->a[0] && stocka->a[size] > main->stockb.a[0]
					&& stocka->a[size] != stocka->big)
		reverse_rotate(stocka, "rra for last_a\n");
	while (stocka->a[size] < stocka->a[0] && stocka->a[size] > main->stockb.a[0]
					&& stocka->a[size] != stocka->big)
		reverse_rotate(stocka, "rra for last_a\n");
	/* ADDED LATE (may have two last elements of a to swap for resolution)
	if (stocka->a[size] < stocka->a[size - 1])
	{
		reverse_rotate(stocka, "rra added\n");
		reverse_rotate(stocka, "rra added\n");
		swap(stocka, "sa\n");
		//lacks two_rotate
	}
	*/
	//printf("PRINTING FROM resolve_last_a >>> END\n");
	//print_stacks_ps(main);
}

int		check_order(t_stock *stocka, t_stock *stockb, t_main *main)
{
	int	i;
	int	tmp;

	i = 0;
	(void)main;
	//printf("_______________________________ check_order\n");
	//print_stacks_ps(main);
	find_biggest(stocka);
	while (stocka->a[i] != stocka->big)
	{
		if (stocka->size <= 5 && stack_order(stocka) != 0)
			resolve_less_than_five(stocka, stockb);
		if (stack_order(stocka) == 0)
			break ;
		else if (stocka->a[i] > stocka->a[i + 1]) //size needed here
		{
			//printf("let me know, unordered value is : %d\n", stocka->a[i]);
			tmp = stocka->a[i];
			while (stocka->a[0] != tmp)
				rotate(stocka, "ra of check_order\n"); /// BIG PROBLEM
			if (stocka->a[0] > stocka->a[1] && stockb->a[0] < stockb->a[1])
			{
				swap(stocka, "");
				swap(stockb, "ss\n");
			}
			else if (stocka->a[0] > stocka->a[1])
			{
			// here resolve_last_a needed but with some more
				//resolve_last_a(stocka, main);
				swap(stocka, "sa\n");
			}
		}
	//printf(">>>>>>>>>> out of second while\n");
		i++;
	}
	//printf(">>>>>>>>>> out of check_order\n");
	return (0);
}

void	find_moves(t_stock *stocka, t_stock *stockb, t_main *main)
{
	printf("_______________________________ find_moves\n");
	resolve_less_than_five(stocka, stockb);
	while (main->stockb.size > 0)
	{
		//printf("____________PRINTING ENTERING find_moves\n");
		/*
		if (stocka->a[stocka->size - 1] == 121)
		{
			printf("I did exit\n");
			print_stacks_ps(main);
			exit(1);
		}
		*/
		exceptions_deal(stocka, stockb, main);
		do_first_operation(stocka, stockb, main); // is insert_bigger_b finally...
		if (stack_order(stocka) != 0)
			resolve_last_a(stocka, main);
		if (stack_order(stocka) != 0)
			check_order(stocka, stockb, main);
		while (stocka->a[stocka->size - 1] < stocka->a[0] && main->stockb.size == 0)
			reverse_rotate(stocka, "rra hope it's the last\n");
		if (stack_order(stocka) == 0 && stockb->size == 0)
		{
			printf("order is gonna break\n");
			break ;
		}
	}
}
