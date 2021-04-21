/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:44:17 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/21 20:44:36 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_iswhitespace(char a)
{
	if (a == '\n' || a == '\t' || a == '\f' ||
		a == ' ' || a == '\r' || a == '\v')
		return (1);
	return (0);
}
