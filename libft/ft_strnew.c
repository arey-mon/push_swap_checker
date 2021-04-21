/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:45:59 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/21 20:46:00 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
