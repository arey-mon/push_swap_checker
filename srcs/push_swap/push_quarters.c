/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:54:20 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 15:54:46 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	push_first_quarter(t_main *main)
{
	find_median(&main->stockb);
	if (main->stocka.a[0] >= main->stockb.median || main->stockb.size == 1)
	{
		push(&main->stocka, &main->stockb, "pb\n");
		if (main->stockb.a[0] < main->stockb.a[1] && main->stockb.size > 4)
			swap(&main->stockb, "sb\n");
	}
	else
	{
		push(&main->stocka, &main->stockb, "pb\n");
		rotate(&main->stockb, "ra\n");
	}
	if (main->stockb.size == 4)
		resolve_less_than_five_b(&main->stockb);
}

void	push_second_quarter(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void	push_third_quarter(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void	push_fourth_quarter(t_main *main)
{
	int		high_median;

	find_median(&main->stockb);
	high_median = (main->stocka.big - main->stocka.three_quarters) / 2 +
		main->stocka.three_quarters;
	if (main->stocka.a[0] < high_median)
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

void	push_quarters(t_main *main, t_stock *stocka, int div)
{
	int		last_a;

	last_a = stocka->a[stocka->size - 1];
	find_biggest(stocka);
	while (*stocka->a != last_a)
	{
		if (div == 0 && *stocka->a <= stocka->quarter)
			push_first_quarter(main);
		else if (div == 1 && *stocka->a >= stocka->quarter && *stocka->a <=
				stocka->median)
			push_second_quarter(main);
		else if (div == 2 && *stocka->a >= stocka->median && *stocka->a <=
				stocka->three_quarters)
			push_third_quarter(main);
		else if (div == 3 && *stocka->a >= stocka->three_quarters &&
				*stocka->a != stocka->big)
			push_fourth_quarter(main);
		else
			rotate(stocka, "ra\n");
	}
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, &main->stockb);
}
