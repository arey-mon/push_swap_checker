/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:22:42 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/20 18:35:43 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i += 1;
	while (i--)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
	}
	return (NULL);
}
