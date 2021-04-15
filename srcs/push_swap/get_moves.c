#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

/*
int		find_insertion(t_stock *stocka, t_stock *stockb, int choice, t_main *main)
{
	(void)stocka;
	(void)stockb;
	int	i;

	i = 0;
	find_smallest(stocka);
	//printf("_______________________________ find_insertion\n");
	//print_stacks_ps(main);
	while (stockb->a[i])
	{
		//printf("you want to insert : %d\n", choice);
		if (stocka->a[0] > stocka->a[1] && stocka->size > 1)
			swap(stocka, "sa that one\n");
		if (find_biggest(stockb) == 0 || find_biggest(stockb) == 1)
		{
			insert_bigger_b(stocka, stockb, main);
			break ;
		}
		else
		{
			if (choice == stockb->small)
			{
				if (stockb->small < stocka->small)
					push(stockb, stocka, "pa 333\n");
			}
			else
				break ;
		}
		i++;
	}
	//printf("_______________________________ >>>>>>>>>>>>>>> find_insertion\n");
	return (0);
}
*/

/*
   here we calculate if it will be faster to get smallest or biggest
   and with which rotation
*/

void	insert_bigger_b(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)main;
	//printf("_______________________________ insert_bigger_b\n");
	find_biggest(stocka);
	find_biggest(stockb);
	//print_stacks_ps(main);
	resolve_last_a(stocka, main);
	if (find_biggest(stockb) == 1 && stockb->size > 1)
		swap(stockb, "sb\n");
	if (stockb->big < stocka->big || stocka->size <= 2) //&& stack_order(stocka) == 0)
	{	
		if (stocka->size < 2 && stockb->big > stocka->big)
		{
			push(stockb, stocka, "pa .!!.\n");
			swap(stocka, "sa this\n"); //what if stocka->size = 1 ??
		}
		int i = 0;
			if (find_biggest(stockb) == 0) //&& stockb->size > 0)
			{
				if (stocka->big > stockb->big)
					while (stockb->big > stocka->a[0])
					{
						rotate(stocka, "ra another one\n"); ///// BUG BUG BUG
						i++;
					}
			}
		push(stockb, stocka, "pa ....\n");
		while (i-- > 1)
			reverse_rotate(stocka, "rra try !!! \n");
		if (stocka->a[0] > stocka->a[1])
			swap(stocka, "sa after pa ...\n");
		}
		else
			push(stockb, stocka, "pa ....\n");
	//print_stacks_ps(main);
}

int		do_first_operation(int moves, int choice, t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)moves;
	(void)stocka;
	(void)main;
	
	if (choice == stockb->big)
		insert_bigger_b(stocka, stockb, main);
	return (0);
}

int		first_operation(t_stock *stocka, t_stock *stockb, t_main *main)
{
	//printf("_______________________________ first_operation\n");
	(void)stocka;
	(void)main;
	int		big_idx;
	int		small_idx;
	int		moves;
	int		b_size;
	int		choice; //may be removed, it's always big_idx

	b_size = (int)stockb->size;
	moves = 0;
	big_idx = find_biggest(stockb);
	small_idx = find_smallest(stockb);
	big_idx = (big_idx > b_size / 2) ? (b_size - 1) - big_idx : big_idx;
	small_idx = (small_idx > b_size / 2) ? (b_size - 1) - small_idx : small_idx;
	moves = (big_idx <= small_idx) ? big_idx : small_idx;
	choice = (big_idx <= small_idx) ? stockb->big : stockb->big;	//stockb->small;
	//printf("moves are = %d, choice is : %d\n", moves, choice);
	//print_stacks_ps(main);
	resolve_last_a(stocka, main);
	do_first_operation(moves, choice, stocka, stockb, main);
	return (0);
}

int		exceptions_deal(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)stocka;
	(void)main;
	//printf("____________ EXCEPTIONS_DEAL\n");
	if (stockb->size <= 4)
		resolve_less_than_five_b(stockb);
	//else if (stocka->size <= 5)
	//	resolve_less_than_five(stocka, stockb);
	//else if (stocka->size <= 9)
	//	resolve_small(stocka, stockb, main);
	//print_stacks_ps(main);
	return (0);
}

void	resolve_last_a(t_stock *stocka, t_main *main)
{
	//printf("_______________________________ resolve_last_a\n");
	int		size;

	size = stocka->size - 1;
	if (stocka->a[size] < stocka->a[0] && stocka->a[size] > main->stockb.a[0]
					&& stocka->a[size] != stocka->big)
		reverse_rotate(stocka, "ra for last-a\n");
	//	printf("PRINTING FROM resolve_last_a >>> END\n");
	//print_stacks_ps(main);
}

int		check_order(t_stock *stocka, t_stock *stockb, t_main *main)
{
	int	i;

	i = 0;
	(void)main;
	(void)stockb;
	printf("_______________________________ check_order\n");
	printf("you're stocka->big is : %d\n", stocka->big);
	print_stacks_ps(main);
	while (stocka->a[i] != stocka->big)
	{
		if (stocka->a[i] > stocka->a[i + 1])
		{
			printf("let me know, unordered value is : %d\n", stocka->a[i]);
			exit (1);
		}
		i++;
	}
	return (0);
}

void	find_moves(t_stock *stocka, t_stock *stockb, t_main *main)
{
	resolve_less_than_five(stocka, stockb);
	while (main->stockb.size > 0)
	{
		//printf("____________PRINTING ENTERING find_moves\n");
		//print_stacks_ps(main);
		exceptions_deal(stocka, stockb, main);
		resolve_last_a(stocka, main);
		first_operation(stocka, stockb, main);
		check_order(stocka, stockb, main);
		if (stocka->a[stocka->size - 1] < stocka->a[0] && main->stockb.size == 0)
			reverse_rotate(stocka, "rra hope it's the last\n");
		if (stack_order(stocka) == 0 && stockb->size == 0)
		{
			printf("order is gonna break\n");
			break ;
		}
	}
}
