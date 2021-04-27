/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:17:36 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/27 16:13:34 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"
#include <string.h>
#include <unistd.h>

int		stack_order(t_stock *stock, int err)
{
	int	i;
	int	ok;

	ok = 0;
	i = 0;
	while (stock->size > 1)
	{
		if (stock->a[i] > stock->a[i + 1])
			ok = 1;
		i++;
		stock->size--;
	}
	if (err == 0)
		(ok == 1) ? write(1, "KO\n", 3) : write(1, "OK\n", 3);
	return (ok == 1) ? 1 : 0;
}

void	free_program(t_pgm *pgm)
{
	free(pgm->stocka.a);
	free(pgm->stockb.a);
}

#include <stdio.h>
int		main(int ac, char **av)
{
	t_pgm			pgm;
	int				ret;
	int				err;

	ret = 0;
	err = 0;
	if (ft_strstr(av[1], "./push_swap") != 0 && stack_order(&pgm.stocka, err) == 0)
	{
		return (0);
	}
	(ac > 1) ? init_stock(&pgm.stocka, &pgm.stockb, &av[1], ac) : exit(1);
	free_program(&pgm);
	if (init_stock(&pgm.stocka, &pgm.stockb, &av[1], ac))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (read_instructions(&pgm.stocka, &pgm.stockb, ret, err))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	free_program(&pgm);
	return (0);
}
