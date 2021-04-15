/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:29:39 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:49:45 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "includes/libft.h"

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*copy;
	size_t			i;
	size_t			ssize;

	i = 0;
	ssize = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start <= ssize)
	{
		while (len--)
		{
			copy[i] = s[start];
			i++;
			start++;
		}
	}
	copy[i] = '\0';
	return (copy);
}

char			*ft_substr_const(char const *s, unsigned int start, size_t len)
{
	char			*copy;
	size_t			i;
	size_t			ssize;

	i = 0;
	ssize = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start <= ssize)
	{
		while (len--)
		{
			copy[i] = s[start];
			i++;
			start++;
		}
	}
	copy[i] = '\0';
	return (copy);
}

char			*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char			*copy;
	size_t			i;
	size_t			ssize;

	i = 0;
	ssize = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start <= ssize)
	{
		while (len--)
		{
			copy[i] = s[start];
			i++;
			start++;
		}
	}
	copy[i] = '\0';
	free(s);
	return (copy);
}
