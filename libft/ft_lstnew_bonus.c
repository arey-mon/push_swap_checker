/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:52:23 by apreymon          #+#    #+#             */
/*   Updated: 2021/04/21 20:45:03 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstnew_size(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size > 0)
	{
		if (!(a->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(a->content, content, content_size);
		a->content_size = content_size;
	}
	else
	{
		a->content = NULL;
		a->content_size = 0;
	}
	a->next = NULL;
	return (a);
}
