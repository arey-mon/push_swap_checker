#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

void	set_biggest_to_top(t_stock *stock)
{
	int	tmp;
	int	save;
	int	size;

	size = stock->size - 1;
	tmp = find_biggest(stock);
	save = stock->a[size];
	stock->a[size] = stock->big;
	stock->a[tmp] = save;
}

//// AINT RIGHT
void	set_biggest_to_bottom(t_stock *stock)
{
	int	tmp;
	int	save;
	int	size;
	
	size = 0;
	tmp = find_biggest(stock);
	printf("tmp = %d, big is = %d\n", tmp, stock->big);
	save = stock->a[size];
	stock->a[size] = stock->big;
	stock->a[tmp] = save;
}

void	arrange_biggest(t_main *main)
{
	if (main->stocka.size > 0)
		set_biggest_to_top(&main->stocka);
	if (main->stockb.size > 0)
		set_biggest_to_top(&main->stockb);
	if (main->stock_middle.size > 0)
		set_biggest_to_bottom(&main->stock_middle);
	if (main->stock_bottom.size > 0)
		set_biggest_to_bottom(&main->stock_bottom);
}
