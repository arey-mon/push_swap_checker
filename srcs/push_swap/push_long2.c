/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_long2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:46:39 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 15:46:46 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	push_median_long(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_six_long(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_seven_long(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_eight_long(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_nine_long(t_pgm *pgm)
{
	int		high_median;

	high_median = (pgm->stocka.big - pgm->stocka.three_quarters) / 2 +
		pgm->stocka.three_quarters;
	if (pgm->stocka.a[0] <= high_median)
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
