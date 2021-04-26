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

void	push_first_quarter(t_pgm *pgm)
{
	find_median(&pgm->stockb);
	if (pgm->stocka.a[0] >= pgm->stockb.median || pgm->stockb.size == 1)
	{
		push(&pgm->stocka, &pgm->stockb, "pb\n");
		if (pgm->stockb.a[0] < pgm->stockb.a[1] && pgm->stockb.size > 4)
			swap(&pgm->stockb, "sb\n");
	}
	else
	{
		push(&pgm->stocka, &pgm->stockb, "pb\n");
		rotate(&pgm->stockb, "ra\n");
	}
	if (pgm->stockb.size == 4)
		resolve_less_than_five_b(&pgm->stockb);
}

void	push_second_quarter(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_third_quarter(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_fourth_quarter(t_pgm *pgm)
{
	int		high_median;

	find_median(&pgm->stockb);
	high_median = (pgm->stocka.big - pgm->stocka.three_quarters) / 2 +
		pgm->stocka.three_quarters;
	if (pgm->stocka.a[0] < high_median)
	{
		push(&pgm->stocka, &pgm->stockb, "pb\n");
		if (pgm->stockb.a[0] < pgm->stockb.a[1])
			swap(&pgm->stockb, "sb\n");
	}
	else
	{
		push(&pgm->stocka, &pgm->stockb, "pb\n");
		rotate(&pgm->stockb, "rb\n");
	}
}

void	push_quarters(t_pgm *pgm, t_stock *stocka, int div)
{
	int		last_a;

	last_a = stocka->a[stocka->size - 1];
	find_biggest(stocka);
	while (*stocka->a != last_a)
	{
		if (div == 0 && *stocka->a <= stocka->quarter)
			push_first_quarter(pgm);
		else if (div == 1 && *stocka->a >= stocka->quarter && *stocka->a <=
				stocka->median)
			push_second_quarter(pgm);
		else if (div == 2 && *stocka->a >= stocka->median && *stocka->a <=
				stocka->three_quarters)
			push_third_quarter(pgm);
		else if (div == 3 && *stocka->a >= stocka->three_quarters &&
				*stocka->a != stocka->big)
			push_fourth_quarter(pgm);
		else
			rotate(stocka, "ra\n");
	}
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, &pgm->stockb);
}
