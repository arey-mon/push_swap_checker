/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:35:59 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/22 15:36:15 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	swap_int(int a, int b)
{
	int	save;

	save = a;
	a = b;
	b = save;
}

void	swap(t_stock *stock, char *str)
{
	int	save;

	if (stock->size > 0)
	{
		save = stock->a[0];
		stock->a[0] = stock->a[1];
		stock->a[1] = save;
	}
	if (stock->write == 1)
		write(1, str, ft_strlen(str));
}

void	rotate(t_stock *stock, char *str)
{
	size_t	i;
	int		tmp;

	tmp = stock->a[0];
	i = 0;
	if (stock->size > 1)
	{
		while (i < stock->size - 1)
		{
			stock->a[i] = stock->a[i + 1];
			i++;
		}
		stock->a[stock->size - 1] = tmp;
	}
	if (stock->write == 1)
		write(1, str, ft_strlen(str));
}

void	reverse_rotate(t_stock *stock, char *str)
{
	int	i;
	int	tmp;

	if (stock->size > 1)
	{
		i = ft_strlen_int(stock->a) - 1;
		i = stock->size - 1;
		tmp = stock->a[i];
		while (i > 0)
		{
			stock->a[i] = stock->a[i - 1];
			i--;
		}
		stock->a[0] = tmp;
	}
	if (stock->write == 1)
		write(1, str, ft_strlen(str));
}
