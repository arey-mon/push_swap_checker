/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:02:22 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/16 15:18:31 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char			*ft_strcpy(char *dest, const char *src)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
		dest[i] = '\0';
	return (dest);
}
