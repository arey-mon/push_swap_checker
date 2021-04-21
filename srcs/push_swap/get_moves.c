#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

/*
int		do_first_operation(t_stock *stocka, t_stock *stockb, t_main *main)
{
	find_biggest(stockb);
	insert_bigger_b(stocka, stockb, main);
	return (0);
}

int		exception_deal(t_stock *stockb)
{
	if (stockb->size <= 4)
		resolve_less_than_five_b(stockb);
	return (0);
}
*/

int		new_check_order(t_stock *stocka)
{
	int	i;

	i = 0;
	printf("_______________________________ new_check_order\n");
	find_biggest(stocka);
	if (stack_order(stocka) == 0)
		return (0) ;
	while (stocka->a[i + 1] != stocka->big)
	{
		if (stocka->a[i] > stocka->a[i + 1])
		{
			printf("new_check_order returns 1.1\n");
		printf("while2, a[i] is = %d && i+1 = %d\n", stocka->a[i], stocka->a[i + 1]);
			return (1);
		}
		i++;
	}
	i += 2;
	while (stocka->a[i] != stocka->a[stocka->size - 1])
	{
		if (stocka->a[i] > stocka->a[i + 1])
		{
		printf("while2, a[i] is = %d && i+1 = %d\n", stocka->a[i], stocka->a[i + 1]);
			printf("new_check_order returns 1.2\n");
			return (1);
		}
		i++;
	}
	printf("new_check_order returns 0\n");
	return(0);
	
}
void	new_algo(t_stock *stocka, t_stock *stockb, t_main *main)
{
	int		size;
	(void)main;

	size = stocka->size - 1;
	find_biggest(stockb);
	find_biggest(stocka);
	find_smallest(stocka);
	find_smallest(stockb);
	//printf("_______________________________ new_algo\n");
	//print_stacks_ps(main);
	while (stockb->a[0] > stocka->a[0])
	{
		rotate(stocka, "ra new_algo\n");
		if (stockb->a[0] < stocka->a[0] && stockb->a[0] > stocka->a[size])
			push(stockb, stocka, "pa3\n");
	}
	resolve_last_a(stocka, main);
	if (stockb->big == stockb->a[stockb->size - 1])
		reverse_rotate(stockb, "rrb3\n");
	if (stocka->a[size] > stockb->a[0] && stocka->a[0] != stocka->small)
		reverse_rotate(stocka, "rra\n");
	else
	{
		resolve_last_a(stocka, main);
		while (stockb->a[0] > stocka->a[0])
			rotate(stocka, "ra new_algo\n");
		push(stockb, stocka, "pa 1\n");
	}
	if (stockb->size == 0 && new_check_order(stocka) == 0)
	{
		while (stocka->a[0] != stocka->small)
		{
			(find_smallest(stocka) > (int)stocka->size / 2) ? reverse_rotate(stocka, "rra\n") : rotate(stocka, "ra\n");
		}
	}
}

void	find_moves(t_stock *stocka, t_stock *stockb, t_main *main)
{
	//printf("_______________________________ find_moves\n");
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, stockb);
	else if (stocka->size > 5 && stocka->size <= 9)
		resolve_small(stocka, stockb, main);
	while (main->stockb.size > 0)
	{
		new_algo(stocka, stockb, main);
		/*
		exception_deal(stockb);
		do_first_operation(stocka, stockb, main);
		if (stack_order(stocka) != 0)
			resolve_last_a(stocka, main);
		if (stack_order(stocka) != 0)
			check_order(stocka, stockb, main);
		while (stocka->a[stocka->size - 1] < stocka->a[0] && main->stockb.size == 0)
			reverse_rotate(stocka, "rra\n");
		*/
		if (stack_order(stocka) == 0 && stockb->size == 0)
			break ;
	}
}
