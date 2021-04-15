/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:45:32 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/15 16:20:57 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>

void	*ft_memccpy(void *restrict dest, const void *restrict src,
					int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
