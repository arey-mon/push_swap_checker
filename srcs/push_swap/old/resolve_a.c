#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int		insert_tmp_val(t_stock *stocka, int i, t_main *main)
{
	printf("_________________________________ TMP_VAL_A\n");
	int	tmp_val;
	int	count;
	(void)main; //only used for printing

	count = 0;
	tmp_val = stocka->a[i];
	printf("your tmp_val is : %d at index : %d\n", tmp_val, i);
	print_stacks_ps(main);
	////// ALL WRONG
	while (stocka->a[1] != tmp_val)
	{
		if (tmp_val < (int)stocka->size / 2)
		{
			reverse_rotate(stocka, "rra\n");
			print_stacks_ps(main);
		}
		else
		{
			rotate(stocka, "ra\n");
			print_stacks_ps(main);
		}
		count++;
	}
	while (count--)
	{ //printf("turning again part B\n");
		if (stocka->a[0] > stocka->a[1])
			swap(stocka, "sa\n");
		if (tmp_val > stocka->pivot)
			rotate(stocka, "ra\n");
		else
			reverse_rotate(stocka, "rra\n");
		//print_stacks_ps(main);
	}
	/* will be used .... ???
	if (tmp_val <= stocka->pivot) it is more (i <= stocka->size / 2) ??
	{}
	else {}
	*/
	return (0);
}

int		resolve_stock_start(t_stock *stocka, t_main *main)
{
	int	i;

	printf("_________________________________ RESOLVE_A\n");
	//								IS INFINITE 888
	i = 0;
	get_pivot(stocka, main);
	while (stocka->a[i])
	{
		if (main->stockb.a[0] > stocka->a[0])
		{
			push(&main->stockb, stocka, "pa\n");
			swap(stocka, "sa\n");
		}
		if (stocka->a[1] < stocka->a[0])
		{
		printf("ELSEIF2\n");
			swap(stocka, "sa\n");
			print_stacks_ps(main);
		}
		if (stocka->a[0] > stocka->pivot)
		{
		//printf("IF1\n");
			rotate(stocka, "ra\n");
			//print_stacks_ps(main);
		}
		if (stocka->a[i] < stocka->a[i - 1] && i > 0)
		{
		//	printf("to insert_tmp_val with i = %d\n", i);
			insert_tmp_val(stocka, i, main);
			break ;
		}
		i++;
	}
	return (stack_order(stocka) == 0) ? 0 : 1;
}
