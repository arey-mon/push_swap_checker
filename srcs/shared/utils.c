#include <stdio.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

int		ft_strlen_int(int *size)
{
	int	i;

	i = 0;
	while (size[i])
		i++;
	return (i);
}

int		integers_check_pos(char *str)
{
	int	stop;
	int	i;

	stop = 0;
	i = 0;
	while (str[i++])
		if (!ft_isdigit(str[i]) && str[i])
		{
			printf("stop from integers_check_pos, str[i] is : [%c]\n", str[i]);
			stop = 1;
		}
	if (ft_strlen(str) >= 10)
	{
		stop = (*str > 57 || *str < 48) ? 1 : 0;
		stop = (str[0] > 50) ? 1 : 0;
		stop = (stop == 1 || str[1] > 49) ? 1 : 0;
		stop = (stop == 1 || str[2] > 52) ? 1 : 0;
		stop = (stop == 1 || str[3] > 55) ? 1 : 0;
		stop = (stop == 1 || str[4] > 52) ? 1 : 0;
		stop = (stop == 1 || str[5] > 56) ? 1 : 0;
		stop = (stop == 1 || str[6] > 51) ? 1 : 0;
		stop = (stop == 1 || str[7] > 54) ? 1 : 0;
		stop = (stop == 1 || str[8] > 52) ? 1 : 0;
		stop = (stop == 1 || str[9] > 55) ? 1 : 0;
	}
	return (stop == 0) ? 0 : 1;
}

int		integers_check_neg(char *str)
{
	int	stop;
	int	i;

	stop = 0;
	i = 0;
	while (str[i++])
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i])
		{
			printf("stop from integers_check_neg\n");
			stop = 1;
		}
	if (ft_strlen(str) >= 10)
	{
		stop = (str[1] > 50) ? 1 : 0;
		stop = (stop == 1 || str[2] > 49) ? 1 : 0;
		stop = (stop == 1 || str[3] > 52) ? 1 : 0;
		stop = (stop == 1 || str[4] > 55) ? 1 : 0;
		stop = (stop == 1 || str[5] > 52) ? 1 : 0;
		stop = (stop == 1 || str[6] > 56) ? 1 : 0;
		stop = (stop == 1 || str[7] > 51) ? 1 : 0;
		stop = (stop == 1 || str[8] > 54) ? 1 : 0;
		stop = (stop == 1 || str[9] > 52) ? 1 : 0;
		stop = (stop == 1 || str[10] > 56) ? 1 : 0;
	}
	return (stop == 0) ? 0 : 1;
}

int		integers_check(char *str)
{
	if (str[0] != '-')
	{
		if (integers_check_pos(str))
			return (1);
	}
	else
	{
		if (integers_check_neg(str))
			return (1);
	}
	return (0);
}

int		ft_atoi_int(char *str)
{
	int	i;
	int	m;
	int	nb;

	i = 0;
	m = 1;
	nb = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * m);
}
