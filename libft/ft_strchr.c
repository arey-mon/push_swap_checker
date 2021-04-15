/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:13:48 by apreymon          #+#    #+#             */
/*   Updated: 2021/04/13 13:08:30 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (0);
}

int		ft_strchr_int(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (0);
		i++;
	}
	return (1);
}

int		ft_strchr_iint(const int *arr, int c)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == (unsigned char)c)
			return (0);
		i++;
	}
	return (1);
}

int		ft_stronechar(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}
