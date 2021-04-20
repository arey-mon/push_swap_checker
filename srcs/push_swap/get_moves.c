#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

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

void	find_moves(t_stock *stocka, t_stock *stockb, t_main *main)
{
	//printf("_______________________________ find_moves\n");
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, stockb);
	else if (stocka->size > 5 && stocka->size <= 9)
		resolve_small(stocka, stockb, main);
	while (main->stockb.size > 0)
	{
		//print_stacks_ps(main);
		exception_deal(stockb);
		do_first_operation(stocka, stockb, main);
		if (stack_order(stocka) != 0)
			resolve_last_a(stocka, main);
		if (stack_order(stocka) != 0)
			check_order(stocka, stockb, main);
		while (stocka->a[stocka->size - 1] < stocka->a[0] && main->stockb.size == 0)
			reverse_rotate(stocka, "rra\n");
		if (stack_order(stocka) == 0 && stockb->size == 0)
			break ;
	}
}
