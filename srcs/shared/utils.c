/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollinereymond <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:37:34 by apolliner         #+#    #+#             */
/*   Updated: 2021/04/27 12:42:56 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

char				*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*pt;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	if (!(pt = malloc((i + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

int		ft_strlen_int(int *size)
{
	int	i;

	i = 0;
	while (size[i])
		i++;
	return (i);
}

int		ft_atoi_int(char *str, int *num)
{
	int		i;
	int		m;
	long	nb;
	char	*ptr;

	m = 1;
	nb = 0;
	ptr = (char *)str;
	if (*ptr == '-' && ptr++)
		m *= -1;
	if (*ptr == '\0')
		return (1);
	i = 0;
	while (*ptr >= '0' && *ptr <= '9' && i++ < 10)
		nb = nb * 10 + *ptr++ - '0';
	if (*ptr != '\0' || nb * m > 2147483647 || nb * m < -2147483648)
		return (1);
	*num = nb * m;
	return (0);
}
