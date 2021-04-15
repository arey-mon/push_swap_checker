/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:27:02 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:49:57 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

size_t			current_size(char const **s, char c)
{
	size_t size;

	size = 0;
	while (**s && **s == c)
		(*s)++;
	while (s[0][size] && s[0][size] != c)
		size++;
	return (size);
}

int				size_to_cut(char const *s, char c)
{
	size_t	nb;
	int		tf;

	nb = 0;
	while (*s)
	{
		tf = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			tf = 1;
			s++;
		}
		if (tf == 1)
			nb++;
	}
	return (nb);
}

char			**free_split(size_t i, char **new)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(new[j]);
		j++;
	}
	free(new);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	size;
	size_t	size_cut;
	size_t	i;

	if (!s)
		return (NULL);
	size = size_to_cut(s, c);
	if (!(res = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		size_cut = current_size(&s, c);
		if (!(res[i] = ft_strndup(s, size_cut)))
			free_split(i, res);
		s += size_cut;
		i++;
	}
	res[size] = NULL;
	return (res);
}
