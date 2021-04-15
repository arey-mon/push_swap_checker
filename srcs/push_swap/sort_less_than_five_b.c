#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int		resolve_three_b(t_stock *stockb)
{
	while (stack_order_b(stockb) != 0)
	{
		if (stockb->a[1] > stockb->a[0])
			swap(stockb, "sb\n");
		if (stockb->a[1] < stockb->a[2])
		{
		printf("IF1\n");
			rotate(stockb, "rb\n");
			swap(stockb, "sb\n");
			reverse_rotate(stockb, "rrb\n");
		}
		else if (stockb->a[stockb->size - 1] > stockb->a[stockb->size - 2])
		{
		printf("IF2\n");
			reverse_rotate(stockb, "rrb\n");
			reverse_rotate(stockb, "rrb\n");
			swap(stockb, "sb\n");
			rotate(stockb, "rb\n");
			rotate(stockb, "rb\n");
		}
	}
	return (0);
}

int		resolve_four_b(t_stock *stockb)
{
	find_biggest(stockb);
	while (stack_order_b(stockb) != 0)
	{
		if (stockb->a[0] < stockb->a[1])
			swap(stockb, "sb\n");
		if (find_biggest(stockb) >= (int)stockb->size / 2)
		{
			while (find_biggest(stockb) != 0)
				reverse_rotate(stockb, "rrb\n");
		}
		if (stockb->a[stockb->size - 1] > stockb->a[stockb->size - 2])
			reverse_rotate(stockb, "rrb\n");
		if (stockb->a[1] < stockb->a[2])
		{
			reverse_rotate(stockb, "rrb\n");
			swap(stockb, "sb\n");
			rotate(stockb, "rrb\n");
		}
	}
	return (0);
}

/*
int		resolve_four_b(t_stock *stockb)
{

	printf("resolve_four_b\n");
	find_biggest(stockb);
	while (stockb->a[0] != stockb->big)
	{
		rotate(stockb, "ra\n");
	}
	resolve_three_b(stockb);
	return (0);
}
*/

int		resolve_less_than_five_b(t_stock *stockb)
{
	int	i;

	//printf("resolve_less_than_five_b\n");
	//printf("b->size = %lu\n", stockb->size);
	i = 0;
	if (stockb->size == 4)
		resolve_four_b(stockb);
	if (stockb->size == 3)
		resolve_three_b(stockb);
	if (stockb->size == 2)
	{
		if (stockb->a[0] < stockb->a[1])
			swap(stockb, "sb\n");
	}
	return (0);
}
