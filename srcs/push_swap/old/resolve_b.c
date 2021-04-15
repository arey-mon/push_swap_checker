#include "../../includes/checker.h"
#include <stdio.h>

void	push_to_a(t_stock *stocka, t_stock *stockb, t_main *main)
{
printf("_____________________ PUSH_TO_A\n");
printf("stockb->b_rr = %d\n", stockb->b_rr);
	if (stockb->s_r >= 0)
		while (stockb->s_r--)
			rotate(stockb, "rb\n");
	else if (stockb->s_rr >= 0)
		while (stockb->s_rr--)
			reverse_rotate(stockb, "rrb\n");
	else if (stockb->b_r >= 0)
		while (stockb->b_r--)
			rotate(stockb, "rb\n");
	else if (stockb->b_rr >= 0)
		while (stockb->b_rr--)
			reverse_rotate(stockb, "rrb\n");
	printf("push you're gonna do is : %d\n", stockb->a[0]);
	push(stockb, stocka, "pa\n");
	(main->small_flag == 1) ? rotate(stocka, "ra\n") : 0;
	//(main->big_flag || !stockb) ? frame->after_rotate++ : 0;
	reset_moves(stockb);
}

int		resolve_b(t_main *main, t_stock *stocka, t_stock *stockb)
{
	int	i;
	int	end;
	int	div;

	end = stockb->size - 1;
	i = 0;
	div = 0;
	find_smallest(stockb);
	while (stockb->a[i])
	{
	//print_stacks_ps(main);
		if (stockb->a[i] == stockb->big || stockb->a[i] == stockb->small)
		{
			push_to_a(stocka, stockb, main);
			break ;
		}
		if (stockb->a[i] == stockb->a[end])
			break ;
		i++;
	}
	(void)main;
	//printf("_____________________ PRINTING FROM RESOLVE_B\n");
	//print_stacks_ps(main);
	return (0);
}
