/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:17:40 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/18 17:29:49 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd);
		i++;
	}
	write(fd, "\n", 1);
}
