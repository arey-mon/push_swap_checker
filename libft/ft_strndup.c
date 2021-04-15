/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:27:02 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:49:03 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strndup(const char *src, size_t len)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i] && i < len)
	{
		dup[j] = src[i];
		i++;
		j++;
	}
	dup[j] = 0;
	return (dup);
}
