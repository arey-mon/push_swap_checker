/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:54:31 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:50:54 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}
