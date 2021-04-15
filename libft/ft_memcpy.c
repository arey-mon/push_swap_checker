/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:45:02 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:47:48 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t			i;
	unsigned char	*destdeux;
	unsigned char	*srcdeux;

	i = 0;
	destdeux = (unsigned char *)dest;
	srcdeux = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < count)
	{
		destdeux[i] = srcdeux[i];
		i++;
	}
	return (destdeux);
}

void	*ft_memcpy_int(void *dest, const void *src, int count)
{
	int				i;
	unsigned char	*destdeux;
	unsigned char	*srcdeux;

	i = 0;
	destdeux = (unsigned char *)dest;
	srcdeux = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < count)
	{
		destdeux[i] = srcdeux[i];
		i++;
	}
	return (destdeux);
}
