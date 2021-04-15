/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:21:11 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/18 17:36:04 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char			*ft_strndup(const char *src, size_t len)
{
	char	*dup;
	size_t	i;

	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

static int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int			to_trim(char c, const char *s)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (to_trim(*s1, set))
		s1++;
	size = ft_strlen((char *)s1);
	i = size;
	while (i-- && to_trim(s1[i], set))
		size--;
	res = ft_strndup(s1, size);
	return (res);
}
