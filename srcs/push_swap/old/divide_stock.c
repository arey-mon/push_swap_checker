#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>



void	divide_stock(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)main;
	find_biggest(stocka);
	//printf("_________________________________DIVIDE_STOCK\n");
	while (stocka->size > 3)
	{
		if (stocka->a[0] != stocka->big)
		{
			push(stocka, stockb, "pb\n");
			if (stockb->a[0] < stockb->a[stockb->size - 1] && stockb->size >= 2)
				rotate(stockb, "rb\n");
			else if (stockb->a[0] < stockb->a[1] && stockb->size >= 2)
				swap(stockb, "sb\n");
		//print_stacks_ps(main);
		}
		else
			rotate(stocka, "ra\n");
	}
	printf("_________________________________ RESOLVE_THREE\n");
	resolve_three(stocka);
	//insert_b(stocka, stockb, main);
	print_stacks_ps(main);
	printf("_________________________________>>>>>DIVIDE_STOCK\n");
}
