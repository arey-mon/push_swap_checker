/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:42:05 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/20 18:00:29 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void		*ft_memcpy(void *dest, const void *src, size_t count)
{
	int				i;
	unsigned char	*destdeux;
	unsigned char	*srcdeux;

	i = 0;
	if (!dest && !src)
		return (NULL);
	destdeux = (unsigned char *)dest;
	srcdeux = (unsigned char *)src;
	while (count--)
	{
		destdeux[i] = srcdeux[i];
		i++;
	}
	return (destdeux);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ddest;
	unsigned char	*ssrc;
	size_t			i;

	i = 0;
	ddest = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (ddest < ssrc && len != 0)
		ft_memcpy(ddest, ssrc, len);
	else
	{
		while (len > 0)
		{
			ddest[len - 1] = ssrc[len - 1];
			len--;
		}
	}
	return (dst);
}
