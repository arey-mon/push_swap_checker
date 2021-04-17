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
		if (stocka->size < 2 && stockb->big > stocka->big)
		{
			push(stockb, stocka, "pa .!!.\n");
			swap(stocka, "sa this\n");
		}
		int i = 0;
		if (find_biggest(stockb) == 0)
		{
			if (stocka->big > stockb->big)
				while (stockb->big > stocka->a[0])
				{
					//resolve_last_a(stocka, main);
					rotate(stocka, "ra another one\n");
					i++;
				}
		}
		resolve_last_a(stocka, main);
		//print_stacks_ps(main);
		// THAT ONE IS A PROBLEM
		push(stockb, stocka, "pa ....\n");
		printf("print after push, then going to resolve_last_a\n");
		print_stacks_ps(main);
		while (i-- > 1)
		{
			printf("stockb->big = %d\n", stockb->big);
			find_biggest(stockb);
			if (stocka->a[stocka->size - 1] < stockb->a[0] && stockb->a[0] == stockb->big)
			{
				push(stockb, stocka, "pa resolve ??\n");
				break ;
			}
		// THAT ONE IS A PROBLEM
		// might rotate lower values of B before pushing A->big
			reverse_rotate(stocka, "rra try !!! \n");
		}
		resolve_last_a(stocka, main);
		if (stocka->a[0] > stocka->a[1])
		{
			//trouble here if you have 159-145-158 for example
			swap(stocka, "sa after pa ...\n");
		}
	}
	// feels like less problems to remove this
	//else
	//	push(stockb, stocka, "pa ...!\n");
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
	int		size;

	size = stocka->size - 1;
	find_biggest(&main->stockb);
	// that should be a good idea but not written right ??
	//if (stocka->a[size] > main->stockb.big)
	{
	if (stocka->a[size] < stocka->a[0] && stocka->a[size] > main->stockb.a[0]
					&& stocka->a[size] != stocka->big)
		reverse_rotate(stocka, "rra for last_a\n");
	/// added that line because it quitted before last move
	if (stocka->a[size] < stocka->a[0] && stocka->a[size] > main->stockb.a[0]
					&& stocka->a[size] != stocka->big)
		reverse_rotate(stocka, "rra for last_a\n");
	}
	/* ADDED LATE (may have two last elements of a to swap for resolution)
	if (stocka->a[size] < stocka->a[size - 1])
	{
		reverse_rotate(stocka, "rra added\n");
		reverse_rotate(stocka, "rra added\n");
		swap(stocka, "sa\n");
		//lacks two_rotate
	}
	*/
		printf("PRINTING FROM resolve_last_a >>> END\n");
	print_stacks_ps(main);
}

int		check_order(t_stock *stocka, t_stock *stockb, t_main *main)
{
	int	i;
	int	tmp;

	i = 0;
	(void)main;
	printf("_______________________________ check_order\n");
	//printf("PRINTING ENTERING check_order\n");
	//print_stacks_ps(main);
	find_biggest(stocka);
	while (stocka->a[i] != stocka->big)
	{
	//exit (1);
		if (stocka->size <= 5)
			resolve_less_than_five(stocka, stockb);
		if (stack_order(stocka) == 0)
			return (0) ;
		else if (stocka->a[i] > stocka->a[i + 1]) //size needed here
		{
			printf("let me know, unordered value is : %d\n", stocka->a[i]);
			print_stacks_ps(main);
			tmp = stocka->a[i];
			//exit (1);
			while (stocka->a[0] != tmp)
			{
				//printf("a[0] = %d, tmp is : %d\n", stocka->a[0], tmp);
				//printf("stocka->big = %d\n", stocka->big);
				//print_stacks_ps(main);
				rotate(stocka, "ra of check_order\n"); /// BIG PROBLEM
			}
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
	printf(">>>>>>>>>> out of check_order\n");
	return (0);
}

void	find_moves(t_stock *stocka, t_stock *stockb, t_main *main)
{
	resolve_less_than_five(stocka, stockb);
	while (main->stockb.size > 0)
	{
		//printf("____________PRINTING ENTERING find_moves\n");
		//
		if (stocka->a[stocka->size - 1] == 131)
		{
			printf("I did exit\n");
			print_stacks_ps(main);
			exit(1);
		}
		//*/
		exceptions_deal(stocka, stockb, main);
		resolve_last_a(stocka, main);
		do_first_operation(stocka, stockb, main); // is insert_bigger_b finally...
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
