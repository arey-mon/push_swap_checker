/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:17:15 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 16:40:28 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <string.h>

int		stack_order_b(t_stock *stock)
{
	int	i;
	int	ok;
	int	size;

	size = stock->size;
	ok = 0;
	i = 0;
	while (i <= size)
	{
		if (stock->a[i] < stock->a[i + 1] && i < size - 1)
			ok = 1;
		i++;
	}
	return (ok == 1) ? 1 : 0;
}

int		stack_order_ps(t_stock *stock)
{
	int	i;
	int	ok;
	int	size;

	size = stock->size;
	ok = 0;
	i = 0;
	while (size > 1)
	{
		if (stock->a[i] > stock->a[i + 1])
			ok = 1;
		i++;
		size--;
	}
	return (ok == 1) ? 1 : 0;
}

void	free_program(t_pgm *pgm)
{
	free(pgm->stocka.a);
	free(pgm->stockb.a);
}

int		resolve(t_pgm *pgm)
{
	if (stack_order_ps(&pgm->stocka) == 0)
		return (0);
	else if (pgm->stocka.size <= 5)
		resolve_less_than_five(&pgm->stocka, &pgm->stockb);
	else if (pgm->stocka.size < 10)
		resolve_small(&pgm->stocka, &pgm->stockb);
	else if (pgm->stocka.size <= 101)
	{
		find_median(&pgm->stocka);
		solve_quarters(&pgm->stocka, pgm);
	}
	else
	{
		find_median_ten(&pgm->stocka);
		solve_ten(&pgm->stocka, pgm);
	}
	if (stack_order_ps(&pgm->stocka) != 0 ||
			(stack_order_b(&pgm->stockb) != 0))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_pgm			pgm;

	pgm.stocka.write = 1;
	pgm.stockb.write = 1;
	(ac > 1) ? init_stock(&pgm.stocka, &pgm.stockb, &av[1], ac) : exit(1);
	free_program(&pgm);
	if (init_stock(&pgm.stocka, &pgm.stockb, &av[1], ac))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	resolve(&pgm);
	if (stack_order_ps(&pgm.stocka) || stack_order_ps(&pgm.stockb))
		find_moves(&pgm.stocka, &pgm.stockb, &pgm);
	free_program(&pgm);
	return (0);
}
