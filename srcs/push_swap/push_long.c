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
