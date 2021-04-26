/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <apreymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:23:56 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/23 15:52:57 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"
#include <stdlib.h>
#include <stddef.h>

int				create_line(char **stock, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*stock)[i] != '\n' && (*stock)[i] != '\0')
		i++;
	if ((*stock)[i] == '\n')
	{
		*line = ft_substr_const(*stock, 0, i);
		tmp = ft_strdup(&((*stock)[i + 1]));
		free(*stock);
		*stock = tmp;
	}
	else
	{
		*line = ft_strdup(*stock);
		if ((*stock)[i] == '\0')
			return (0);
		free(*stock);
		*stock = NULL;
	}
	return (1);
}

int				get_next_line2(int fd, char **line)
{
	if ((fd < 0) || (line == NULL))
	{
		return (-1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*rest[1000];
	char			*ret_string;
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	get_next_line2(fd, line);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (rest[fd] == NULL)
			rest[fd] = ft_strdup(buf);
		else
		{
			ret_string = ft_strjoin(rest[fd], buf);
			free(rest[fd]);
			rest[fd] = ret_string;
		}
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	if (ret == 0 && *rest[fd] == '\0')
		return (0);
	return (check_ret(ret, fd, rest, line));
}

int				check_ret(int ret, int fd, char **stock, char **line)
{
	if (ret < 0)
		return (-1);
	else
		return (create_line(&stock[fd], line));
}
