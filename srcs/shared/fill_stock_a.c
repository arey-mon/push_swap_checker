/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stock_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:59:03 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 15:15:33 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

int		get_args_size(char **arg, int ac)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int		split_args(char *fill, t_stock *stock, int i)
{
	int	num;

	while (*fill)
	{
		if (*fill == '-')
		{
			fill++;
			if (!ft_isdigit(*fill))
				return (1);
			else
				fill--;
		}
		if (!ft_isdigit(*fill) && *fill != '-' && *fill)
			return (1);
		else
		{
			if (ft_atoi_int(fill, &num))
				return (1);
			else
				ft_atoi_int(fill, &num);
			stock->a[i] = num;
			stock->size++;
			break ;
		}
		fill++;
	}
	return (0);
}

int		check_duplicates(t_stock *stock)
{
	int	i;
	int	j;
	int	size;

	size = stock->size;
	i = 0;
	while (i < (int)stock->size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stock->a[j] == stock->a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_stack(int ac, char **arg, t_stock *stocka)
{
	int		i;
	char	*fill;

	i = 0;
	while (i < ac - 1)
	{
		fill = arg[i];
		if (ft_strlen(fill) < 1)
			exit(1);
		if (split_args(fill, stocka, i))
			return (1);
		i++;
	}
	if (check_duplicates(stocka))
		return (1);
	return (0);
}

int		init_stock(t_stock *stocka, t_stock *stockb, char **arg, int ac)
{
	int		malloc_size;
	malloc_size = get_args_size(arg, ac);
	if (!(stocka->a = (int *)malloc(sizeof(int) * malloc_size)))
		return (1);
	if (!(stockb->a = (int *)malloc(sizeof(int) * malloc_size)))
		return (1);
	stocka->size = 0;
	stockb->size = 0;
	if (fill_stack(ac, arg, stocka))
		return (1);
	return (0);
}
