#include <stdio.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

int		get_args_size(char **arg, int ac)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int		split_args(char *fill, t_stock *stock, int i)
{
	int	num;

	while (*fill)
	{
		if (*fill == '-')
		{
			fill++;
			if (!ft_isdigit(*fill))
			{
				write(1, "Error\n", 6);
printf("error from !isdigit, '-' is not followed by a number : [%c]\n", *fill);
			}
			else
			fill--;
		}
		if (!ft_isdigit(*fill) && *fill != '-' && *fill)
		{
			write(1, "Error\n", 6);
			printf("error from !isdigit, *fill is : [%c]\n", *fill);
			return (1);
		}
		else
		{
			if (ft_strlen(fill) >= 2)
			{
				if (integers_check(fill))
				{
					printf("integers_check error\n");
					return (1);
				}
				num = ft_atoi_int(fill);
			}
			else
				num = ft_atoi(fill);
			stock->a[i] = num;
			stock->size++;
			break ;
		}
		fill++;
	}
	return (0);
}

int		check_duplicates(t_stock *stock)
{
	int	i;
	int	j;
	int	size;

	size = stock->size;
	i = 0;
	//j = 1;
	// j never increments
	while (i < (int)stock->size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stock->a[j] == stock->a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_stack(int ac, char **arg, t_stock *stocka)
{
	int		i;
	char	*fill;

	i = 0;
	while (i < ac - 1)
	{
		fill = arg[i];
		if (ft_strlen(fill) < 1)
			exit(1);
		if (split_args(fill, stocka, i))
			return (1);
		i++;
	}
	if (check_duplicates(stocka))
		return (1);
	return (0);
}

int		init_stock(t_stock *stocka, t_stock *stockb, char **arg, int ac)
{
	int		malloc_size;

	malloc_size = get_args_size(arg, ac);
	printf("malloc_size : %d\n", malloc_size);
	if (!(stocka->a = (int *)malloc(sizeof(int) * malloc_size)))
		exit(1);
	if (!(stockb->a = (int *)malloc(sizeof(int) * malloc_size)))
		exit(1);
	stocka->size = 0;
	stockb->size = 0;
	if (fill_stack(ac, arg, stocka))
	{
	// THOSE FREE RESULT IN ABORT IF YOU DO FOR EXAMPLE
	// ./checker 2 -1 1 -42 -24 -a 1 >> Ctl+D
		//free(stocka->a);
		//free(stockb->a);
		write(1, "Error\n", 6);
		printf("Error from init_stock (fill_stack)\n");
		return (1); //should not before all instructions are wrote
	}
	return (0);
}
