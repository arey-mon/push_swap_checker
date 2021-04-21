/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:02:22 by apreymon          #+#    #+#             */
/*   Updated: 2021/04/21 20:55:55 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	return (ft_strlen(src));
}
