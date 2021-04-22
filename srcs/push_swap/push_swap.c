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

void	free_program(t_main *main)
{
	free(main->stocka.a);
	free(main->stockb.a);
}

int		resolve(t_main *main)
{
	if (stack_order_ps(&main->stocka) == 0)
		return (0);
	else if (main->stocka.size <= 5)
		resolve_less_than_five(&main->stocka, &main->stockb);
	else if (main->stocka.size < 10)
		resolve_small(&main->stocka, &main->stockb);
	else if (main->stocka.size <= 101)
	{
		find_median(&main->stocka);
		solve_quarters(&main->stocka, main);
	}
	else
	{
		find_median_ten(&main->stocka);
		solve_ten(&main->stocka, main);
	}
	if (stack_order_ps(&main->stocka) != 0 ||
			(stack_order_b(&main->stockb) != 0))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_main			main;

	main.stocka.write = 1;
	main.stockb.write = 1;
	(ac > 1) ? init_stock(&main.stocka, &main.stockb, &av[1], ac) : exit(1);
	free_program(&main);
	if (init_stock(&main.stocka, &main.stockb, &av[1], ac))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	resolve(&main);
	if (stack_order_ps(&main.stocka) || stack_order_ps(&main.stockb))
		find_moves(&main.stocka, &main.stockb, &main);
	free_program(&main);
	return (0);
}
