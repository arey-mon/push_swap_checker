/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:37:38 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:48:35 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "includes/libft.h"

#include <stdio.h>
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (((unsigned char)s1[i] || (unsigned char)s2[i]) &&
	(unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	printf("res from strcmp : %d\n", ((unsigned char)s1[i] - (unsigned char)s2[i]));
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
