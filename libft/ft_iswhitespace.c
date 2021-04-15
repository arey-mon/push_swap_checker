#include <stdio.h>
#include "includes/libft.h"

int ft_iswhitespace(char a)
{
	if (a == '\n' || a == '\t' || a == '\f' ||
		a == ' ' || a == '\r' || a == '\v')
		return (1);
	return (0);
}
