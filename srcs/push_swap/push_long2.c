#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

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
	int		high_median;

	high_median = (main->stocka.big - main->stocka.three_quarters) / 2 +
											main->stocka.three_quarters;
	if (main->stocka.a[0] <= high_median)
	{
		push(&main->stocka, &main->stockb, "pb\n");
		if (main->stockb.a[0] < main->stockb.a[1])
			swap(&main->stockb, "sb\n");
	}
	else
	{
		push(&main->stocka, &main->stockb, "pb\n");
		rotate(&main->stockb, "rb\n");
	}
}
