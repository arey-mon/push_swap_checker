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
	if (*ptr != '\0' || nb * m > 2147483647 ||  nb * m < -2147483648)
		return (1);
	*num = nb * m;
	return (0);
}

/*
int		integers_check_pos(char *str)
{
	(void)str;

	int	i;

	stop = 0;
	i = 0;
	stop = (ft_strlen(str) > 10) ? 1 : 0;
	while (str[i++])
		if (!ft_isdigit(str[i]) && str[i])
			stop = 1;
	if (ft_strlen(str) == 10)
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
	stop = integers_check_int(str, i) == 0 ? 0 : 1;
	return (0);
}

int		integers_check_neg(char *str)
{
	(void)str;
	int	stop;
	int	i;

	stop = 0;
	i = 0;
	stop = (ft_strlen(str) > 11) ? 1 : 0;
	if (ft_strlen(str) == 11)
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
	printf("integers_check_neg returns : %d\n", stop);
	return (stop == 0) ? 0 : 1;
	return (0);
}

int		integers_check(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i])
			return (1);
	if (str[0] != '-')
	{
		if (integers_check_pos(str))
			return (1);
	}
	else
	{
		while (str[i++] != '-')
			if (str[i - 1] != ' ' && i != 0)
				return (1);
		if (integers_check_neg(str))
			return (1);
	}
	return (0);
}
*/
