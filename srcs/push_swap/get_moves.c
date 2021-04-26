/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:57:38 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 16:06:23 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

int		new_check_order(t_stock *stocka)
{
	int	i;

	i = 0;
	find_biggest(stocka);
	if (stack_order_ps(stocka) == 0)
		return (0);
	while (stocka->a[i + 1] != stocka->big)
	{
		if (stocka->a[i] > stocka->a[i + 1])
			return (1);
		i++;
	}
	i += 2;
	while (stocka->a[i] != stocka->a[stocka->size - 1])
	{
		if (stocka->a[i] > stocka->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	prepare_algo(t_stock *stocka, t_stock *stockb)
{
	find_biggest(stockb);
	find_biggest(stocka);
	find_smallest(stocka);
	find_smallest(stockb);
}

void	find_rotation(t_stock *stocka)
{
	while (stocka->a[0] != stocka->small)
	{
		(find_smallest(stocka) > (int)stocka->size / 2) ?
		reverse_rotate(stocka, "rra\n") : rotate(stocka, "ra\n");
	}
}

void	new_algo(t_stock *stocka, t_stock *stockb, t_pgm *pgm)
{
	int		size;

	size = stocka->size - 1;
	prepare_algo(stocka, stockb);
	while (stockb->a[0] > stocka->a[0])
	{
		rotate(stocka, "ra\n");
		if (stockb->a[0] < stocka->a[0] && stockb->a[0] > stocka->a[size])
			push(stockb, stocka, "pa\n");
	}
	resolve_last_a(stocka, pgm);
	if (stockb->big == stockb->a[stockb->size - 1])
		reverse_rotate(stockb, "rrb\n");
	if (stocka->a[size] > stockb->a[0] && stocka->a[0] != stocka->small)
		reverse_rotate(stocka, "rra\n");
	else
	{
		resolve_last_a(stocka, pgm);
		while (stockb->a[0] > stocka->a[0])
			rotate(stocka, "ra\n");
		push(stockb, stocka, "pa\n");
	}
	if (stockb->size == 0 && new_check_order(stocka) == 0)
		find_rotation(stocka);
}

void	find_moves(t_stock *stocka, t_stock *stockb, t_pgm *pgm)
{
	if (stocka->size <= 5)
		resolve_less_than_five(stocka, stockb);
	else if (stocka->size > 5 && stocka->size <= 9)
		resolve_small(stocka, stockb);
	while (pgm->stockb.size > 0)
	{
		new_algo(stocka, stockb, pgm);
		if (stack_order_ps(stocka) == 0 && stockb->size == 0)
			break ;
	}
}
