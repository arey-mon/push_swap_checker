/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_small_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:20:31 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/21 20:07:55 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

void	resolve_small(t_stock *stocka, t_stock *stockb)
{
	find_median(stocka);
	while (stocka->size > 5)
	{
		if (*stocka->a < stocka->median)
			push(stocka, stockb, "pb\n");
		else
			rotate(stocka, "ra\n");
	}
	resolve_less_than_five(stocka, stockb);
	resolve_less_than_five_b(stockb);
	if (stack_order_b(stockb) == 0)
		while (stockb->size > 0)
			push(stockb, stocka, "pa\n");
}

int		resolve_five(t_stock *stocka, t_stock *stockb)
{
	int	count;

	count = 0;
	while (count != 2)
	{
		if (find_smallest(stocka) >= 3)
			while (stocka->a[0] != stocka->small)
				reverse_rotate(stocka, "ra\n");
		else
			while (stocka->a[0] != stocka->small)
				rotate(stocka, "ra\n");
		push(stocka, stockb, "pb\n");
		count++;
	}
	resolve_three(stocka);
	push(stockb, stocka, "pa\n");
	push(stockb, stocka, "pa\n");
	return (0);
}

int		resolve_three(t_stock *stocka)
{
	int		big_idx;

	big_idx = find_biggest(stocka);
	if (big_idx == 0)
		rotate(stocka, "ra\n");
	else if (big_idx == 1)
		reverse_rotate(stocka, "rra\n");
	if (stocka->a[0] > stocka->a[1])
		swap(stocka, "sa\n");
	return (0);
}

int		resolve_four(t_stock *stocka, t_stock *stockb)
{
	find_smallest(stocka);
	while (stocka->a[0] != stocka->small)
		rotate(stocka, "ra\n");
	push(stocka, stockb, "pb\n");
	resolve_three(stocka);
	push(stockb, stocka, "pa\n");
	return (0);
}

int		resolve_less_than_five(t_stock *stocka, t_stock *stockb)
{
	if (stocka->size == 1)
		return (0);
	else if (stocka->size == 2 && stocka->a[0] > stocka->a[1])
		swap(stocka, "sa\n");
	else if (stocka->size == 3)
		resolve_three(stocka);
	else if (stocka->size == 4)
		resolve_four(stocka, stockb);
	else if (stocka->size == 5)
		while (stack_order(stocka))
			resolve_five(stocka, stockb);
	return (0);
}
