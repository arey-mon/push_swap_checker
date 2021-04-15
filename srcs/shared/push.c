#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../includes/checker.h"
#include "../../libft/includes/libft.h"

void	erase(t_stock *stack, size_t index)
{
	size_t i;

	if (stack->size == 0 || index >= stack->size)
		return ;
	i = index;
	while (i < stack->size)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size--;
}

void	push_val(t_stock *dest, int val)
{
	int i;

	i = dest->size;
	while (i > 0)
	{
		dest->a[i] = dest->a[i - 1];
		i--;
	}
	dest->a[0] = val;
	dest->size++;
}

int		push(t_stock *src, t_stock *dest, char *str)
{
	if (src->size > 0)
	{
		push_val(dest, src->a[0]);
		erase(src, 0);
	}
	if (src->write == 1)
		write(1, str, ft_strlen(str));
	return (0);
}
