/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:47:01 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 15:53:16 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	resolve_last_a(t_stock *stocka, t_pgm *pgm)
{
	int		size;

	size = stocka->size - 1;
	find_biggest(&pgm->stockb);
	if (find_biggest(&pgm->stockb) > (int)pgm->stockb.size / 2 - 1 &&
			pgm->stockb.size > 2)
	{
		while (find_biggest(&pgm->stockb) != 0)
			reverse_rotate(&pgm->stockb, "rrb\n");
	}
	while (stocka->a[size] < stocka->a[0] && stocka->a[size] > pgm->stockb.a[0]
			&& stocka->a[size] != stocka->big)
		reverse_rotate(stocka, "rra\n");
}

int		check_order2(t_stock *stocka, t_stock *stockb, int i, int tmp)
{
	if (stocka->size <= 5 && stack_order_ps(stocka) != 0)
		resolve_less_than_five(stocka, stockb);
	if (stack_order_ps(stocka) == 0)
		return (0);
	else if (stocka->a[i] > stocka->a[i + 1])
	{
		tmp = stocka->a[i];
		while (stocka->a[0] != tmp)
			rotate(stocka, "ra\n");
		if (stocka->a[0] > stocka->a[1] && stockb->a[0] < stockb->a[1])
		{
			swap(stocka, "");
			swap(stockb, "ss\n");
		}
		else if (stocka->a[0] > stocka->a[1])
			swap(stocka, "sa\n");
		return (1);
	}
	return (0);
}

int		check_order(t_stock *stocka, t_stock *stockb, t_pgm *pgm)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	(void)pgm;
	while (stocka->a[i] != stocka->big)
	{
		check_order2(stocka, stockb, i, tmp);
		i++;
	}
	return (0);
}
