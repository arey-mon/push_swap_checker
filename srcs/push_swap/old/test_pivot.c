#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

/*
void		search_pivot(t_main *main, t_stock *stocka, t_stock *stockb)
{
	if (stocka->size > 0)
		get_pivot(stocka);
	if (stockb->size > 0)
		get_pivot(&main->stockb);
	if (main->stock_bottom.size > 0)
		get_pivot(&main->stock_bottom);
	if (main->stock_middle.size > 0)
		get_pivot(&main->stock_middle);
}

int		get_pivot(t_stock *stock)
{
	int	i;
	unsigned int	pivot;

	i = 0;
	pivot = stock->a[stock->size - 1];
	launch_sort(stock, pivot);
	printf("your pivot is : %d\n", pivot);
	return (pivot);
}

int		launch_sort(t_stock *stock, int pivot)
{
	int	i;
	int	tmp;
	int	tmp2;
	int	idx_save;

	idx_save = 0;
	i = 0;
	tmp = 0;
	tmp2 = 0;
	printf("stock->size = %lu\n", stock->size);
	while (stock->a[i])
	{
		//printf("your stock is : %d\n", stock->a[i]);
		if (pivot == find_biggest(stock))
		{
			printf("let me know\n");
			stock->a[stock->size - 1] = pivot;
			pivot = stock->a[stock->size - 2];
		}
		if (stock->a[i] > pivot)
		{
			tmp = stock->a[i];
			idx_save = i;
			printf("tmp is : %d\n", tmp);
		}
		else if (stock->a[i] < tmp)
		{
			if (stock->a[i] < tmp2 && tmp2 != 0)
				tmp2 = stock->a[i];
			printf("tmp2 is : %d\n", tmp2);
			stock->a[i] = tmp;
			stock->a[idx_save] = tmp2;
			break ;
		}
		i++;
	}
	return (0);
}
*/

int		quick_sort(t_stock *stocka, t_stock *stockb, t_main *main)
{
	(void)stockb;
	main->malloc_size_bottom = 0;
	main->malloc_size_up = 0;
	get_malloc_size(stocka, main);
	create_stock(stocka, &main->stock_bottom, &main->stock_middle);
	set_biggest_to_top(stock);

	//search_pivot(main, stocka, stockb);
	printf("___________________________\n");
	return (0);
}
