/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:16:58 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/15 18:25:48 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int	ft_nbrlen(int f)
{
	int	i;
	int	res;

	res = f;
	i = 0;
	if (f == 0)
		return (1);
	while (f != 0)
	{
		f = f / 10;
		i++;
	}
	if (res < 0)
		return (i + 1);
	return (i);
}

char		*ft_itoa(int n)
{
	char	*tmp;
	long	nb;
	int		i;
	int		d;

	i = 0;
	d = 1;
	nb = n;
	if (!(tmp = malloc(sizeof(char) * ft_nbrlen((int)nb) + 1)))
		return (NULL);
	if (nb < 0)
	{
		tmp[i] = '-';
		nb *= -1;
		i++;
	}
	while (nb / d >= 10)
		d *= 10;
	while (d > 0)
	{
		tmp[i++] = (nb / d) % 10 + '0';
		d /= 10;
	}
	tmp[i] = '\0';
	return (tmp);
}
