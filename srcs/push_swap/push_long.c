/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:46:11 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 15:55:01 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	push_first_long(t_main *main)
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

void	push_second_long(t_main *main)
{
	push(&main->stocka, &main->stockb, "pb\n");
	if (main->stockb.a[0] < main->stockb.a[1])
		swap(&main->stockb, "sb\n");
}

void	push_third_long(t_main *main)
{
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

void	push_long(t_main *main, t_stock *stocka, int div)
{
	int		last_a;

	last_a = stocka->a[stocka->size - 1];
	find_biggest(stocka);
	while (*stocka->a != last_a)
	{
		if (div == 0 && *stocka->a <= stocka->first_long)
			push_first_long(main);
		else if (div == 1 && *stocka->a >= stocka->first_long && *stocka->a <=
				stocka->second_long)
			push_second_long(main);
		else if (div == 2 && *stocka->a >= stocka->second_long && *stocka->a <=
				stocka->third_long)
			push_third_long(main);
		else if (div == 3 && *stocka->a >= stocka->third_long && *stocka->a <=
				stocka->fourth_long)
			push_fourth_long(main);
		else if (div == 4 && *stocka->a >= stocka->fourth_long && *stocka->a <=
				stocka->median_long)
			push_median_long(main);
		else if (div == 5 && *stocka->a >= stocka->median_long && *stocka->a <=
				stocka->six_long)
			push_six_long(main);
		else if (div == 6 && *stocka->a >= stocka->six_long && *stocka->a <=
				stocka->seven_long)
			push_seven_long(main);
		else if (div == 7 && *stocka->a >= stocka->seven_long && *stocka->a <=
				stocka->eight_long)
			push_eight_long(main);
		else if (div == 8 && *stocka->a >= stocka->eight_long && *stocka->a <=
				stocka->nine_long && *stocka->a != stocka->big)
			push_nine_long(main);
		else
			rotate(stocka, "ra\n");
	}
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, &main->stockb);
}
