/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_smallest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:54:02 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 15:54:06 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

int		find_biggest(t_stock *stock)
{
	int		i;
	int		size_up;
	int		idx;

	i = 0;
	size_up = stock->size - 1;
	stock->big = stock->a[i];
	idx = i;
	while (size_up >= 0)
	{
		if (stock->a[i] > stock->big)
		{
			stock->big = stock->a[i];
			idx = i;
		}
		size_up--;
		i++;
	}
	return (idx);
}

int		find_smallest(t_stock *stock)
{
	int				i;
	int				size_bottom;
	int				idx;

	i = 0;
	size_bottom = stock->size - 1;
	stock->small = stock->a[i];
	idx = i;
	while (size_bottom >= 0)
	{
		if (stock->a[i] < stock->small)
		{
			stock->small = stock->a[i];
			idx = i;
		}
		size_bottom--;
		i++;
	}
	return (idx);
}
