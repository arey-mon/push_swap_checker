/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:45:08 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/21 20:45:10 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	new = (void*)malloc(size * sizeof(size_t));
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
