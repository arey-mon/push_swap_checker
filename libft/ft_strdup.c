/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:13:49 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:48:43 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	while (s1[i])
		i++;
	if (!(copy = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
