#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	push_first_long(t_main *main)
{
	//printf("push_first_long\n");
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

void	push_median_long(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void	push_six_long(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}
void	push_seven_long(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}
void	push_eight_long(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}
void	push_nine_long(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void		push_long(t_main *main, t_stock *stocka, int div)
{
	(void)main;
	int		last_a;

	printf("__________________________________ push_quarters\n");
	printf("div = %d\n", div);
	//print_stacks_ps(main);
	last_a = stocka->a[stocka->size - 1];
	find_biggest(stocka);
	while (*stocka->a != last_a)
	{
		if (div == 0 && *stocka->a <= stocka->first_long)
			push_first_long(main);
		else if (div == 1 && *stocka->a >= stocka->first_long && *stocka->a <= stocka->second_long)
			 push_second_long(main);
		else if (div == 2 && *stocka->a >= stocka->second_long && *stocka->a <= stocka->third_long)
			push_third_long(main);
		else if (div == 3 && *stocka->a >= stocka->third_long && *stocka->a <= stocka->fourth_long)
			push_fourth_long(main);
		else if (div == 4 && *stocka->a >= stocka->fourth_long && *stocka->a <= stocka->median_long)
			push_median_long(main);
		else if (div == 5 && *stocka->a >= stocka->median_long && *stocka->a <= stocka->six_long)
			push_six_long(main);
		else if (div == 6 && *stocka->a >= stocka->six_long && *stocka->a <= stocka->seven_long)
			push_seven_long(main);
		else if (div == 7 && *stocka->a >= stocka->seven_long && *stocka->a <= stocka->eight_long)
			push_eight_long(main);
		else if (div == 8 && *stocka->a >= stocka->eight_long && *stocka->a <= stocka->nine_long && *stocka->a != stocka->big)
			push_nine_long(main);
		else
			rotate(stocka, "ra\n");
		//
		//if (div == 9)
		//	exit (1);
	}
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, &main->stockb);
	//printf("______________________ PRINTING AFTER PUSH_QUARTERS\n");
	//print_stacks_ps(main);
}