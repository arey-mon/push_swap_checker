/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:46:11 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 16:10:16 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	push_first_long(t_pgm *pgm)
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

void	push_second_long(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_third_long(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}

void	push_fourth_long(t_pgm *pgm)
{
	push(&pgm->stocka, &pgm->stockb, "pb\n");
	if (pgm->stockb.a[0] < pgm->stockb.a[1])
		swap(&pgm->stockb, "sb\n");
}
