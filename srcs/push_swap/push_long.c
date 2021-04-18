#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	push_first_long(t_main *main)
{
	//printf("push_first_quarter\n");
	//print_stacks_ps(main);
	find_median(main, &main->stockb);
	if (main->stocka.a[0] >= main->stockb.median || main->stockb.size == 1)
	{
		push(&main->stocka, &main->stockb, "pb\n");
		if (main->stockb.a[0] < main->stockb.a[1] && main->stockb.size > 4)
			swap(&main->stockb, "sb\n");
	}
	else
	{
		push(&main->stocka, &main->stockb, "pb\n");
		rotate(&main->stockb, "ra from first_quarter\n");
	}
	if (main->stockb.size == 4)
		resolve_less_than_five_b(&main->stockb);
	//print_stacks_ps(main);
}

void	push_second_long(t_main *main)
{
//printf("push_second_quarter\n");
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void	push_third_long(t_main *main)
{
//printf("push_third_quarter\n");
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void	push_fourth_long(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void		push_quarters(t_main *main, t_stock *stocka, int div)
{
	(void)main;
	int		last_a;

	//printf("__________________________________ push_quarters\n");
	//print_stacks_ps(main);
	last_a = stocka->a[stocka->size - 1];
	find_biggest(stocka);
	while (*stocka->a != last_a)
	{
	//printf("stocka->a : %d, div : %d\n", *stocka->a, div);
		if (div == 0 && *stocka->a <= stocka->quarter)
			push_first_quarter(main);
		// I exit here
			//print_stacks_ps(main);
			/*if (div == 3)
			{
				print_stacks_ps(main);
				printf("stockb->size after first_quarter push is : %lu\n", main->stockb.size);
				exit (1);
			}
			*/
		else if (div == 1 && *stocka->a > stocka->quarter && *stocka->a <= stocka->median)
			 push_second_quarter(main);
		else if (div == 2 && *stocka->a > stocka->median && *stocka->a <= stocka->three_quarters)
			push_third_quarter(main);
		else if (div == 3 && *stocka->a > stocka->three_quarters && *stocka->a != stocka->big)
			push_fourth_quarter(main);
		else
			rotate(stocka, "ra\n");
	}
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, &main->stockb);
	//printf("______________________ PRINTING AFTER PUSH_QUARTERS\n");
	//print_stacks_ps(main);
}
