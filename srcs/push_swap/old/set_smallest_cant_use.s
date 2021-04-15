#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

// FORBIDDEN
// I need to use the operations assigned
void	set_smallest_to_top(t_stock *stock)
{
	int	tmp;
	int	save;
	int	size;

	size = stock->size - 1;
	tmp = find_smallest(stock);
	save = stock->a[size];
	stock->a[size] = stock->small;
	stock->a[tmp] = save;
}

void	set_smallest_to_bottom(t_stock *stock)
{
	int	tmp;
	int	save;
	int	size;
	
	size = 0;
	tmp = find_smallest(stock);
	save = stock->a[size];
	stock->a[size] = stock->small;
	stock->a[tmp] = save;
}

void	arrange_smallest(t_main *main)
{
	printf("arrange_smallest\n");
	if (main->stocka.size > 0)
		set_smallest_to_bottom(&main->stocka);
	if (main->stockb.size > 0)
		set_smallest_to_bottom(&main->stockb);
	if (main->stock_middle.size > 0)
		set_smallest_to_top(&main->stock_middle);
	if (main->stock_bottom.size > 0)
		set_smallest_to_top(&main->stock_bottom);
}
