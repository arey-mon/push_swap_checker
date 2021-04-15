/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:41:42 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/20 16:56:02 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

static void		*ft_memset(void *ptr, int value, size_t count)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (count--)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

void			*ft_calloc(size_t count, size_t size)
{
	unsigned int	ssize;
	unsigned char	*ptr;

	ssize = count * size;
	if (!(ptr = malloc(ssize)))
		return (NULL);
	ft_memset(ptr, 0, ssize);
	return (ptr);
}
