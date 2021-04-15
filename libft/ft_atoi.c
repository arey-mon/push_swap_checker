/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:02:04 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:47:24 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int m;
	int nb;

	i = 0;
	m = 1;
	nb = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r'))
	{
		i++;
	}
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * m);
}
