#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

/*
int		create_stock(t_stock *stocka, t_stock *stock_bottom, t_stock *stock_middle)
{
	int		size;
	int		k;
	int		l;
	int		i;
	int		count;

	k = 0;
	l = 0;
	i = 0;
	size = stocka->size;

	char *fill = ft_itoa(stocka->a[i]);
	count = ft_strlen(fill);
	// THAT WAY IS FORBIDDEN CAUSE IT AINT NO PUSH(B)
	while (size)
	{
		char *fill = ft_itoa(stocka->a[i]);
		count = ft_strlen(fill);
		if (stocka->a[i] < 0 && count > 2)
		{
			stock_bottom->a[k] = stocka->a[i];
			erase(stocka, i);
			i--;
			k++;
		}
		else if (stocka->a[i] >= 0 && count == 1)
		{
			stock_middle->a[l] = stocka->a[i];
			erase(stocka, i);
			i--;
			l++;
		}
		size--;
		i++;
	}
	/////
	printf("ending create_stock with st->a = %d\n", stocka->a[0]);
	return (0);
}
*/

void	init_empty_stocks(t_stock *stock_bottom, t_stock *stock_middle)
{
		if (stock_bottom->size == 0)
		{
			if (!(stock_bottom->a = (int *)malloc(sizeof(int) * 2)))
				printf("malloc failed\n");
			*stock_bottom->a = 0;
		}
		if (stock_middle->size == 0)
		{
			if (!(stock_middle->a = (int *)malloc(sizeof(int) * 2)))
				printf("malloc failed\n");
			 *stock_middle->a = 0; //tried other stuff without success
		}
}

void	get_malloc_size(t_stock *stocka, t_main *main)
{
	int		size;
	int		i;
	int		count;

	size = stocka->size;
	i = 0;
	count = 0;
	main->malloc_size_bottom = count;
	main->malloc_size_up = count;
	while (size)
	{
	/*
		char *fill = ft_itoa(stocka->a[i]);
		count = ft_strlen(fill);
		if (stocka->a[i] < 0 && count > 2)
		{
			main->stock_bottom.size++;
			main->malloc_size_bottom += count;
			if (!(main->stock_bottom.a = (int *)malloc(sizeof(int) * main->malloc_size_bottom)))
				printf("malloc failed\n");
		}
		else if (stocka->a[i] >= 0 && count == 1) //
		{
			main->stock_middle.size++;
			main->malloc_size_up += count;
			if (!(main->stock_middle.a = (int *)malloc(sizeof(int) * main->malloc_size_up)))
				printf("malloc failed\n");
		}
		*/
		init_empty_stocks(&main->stock_bottom, &main->stock_middle);
		size--;
		i++;
	}
}
