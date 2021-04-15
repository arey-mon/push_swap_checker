#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	new = (void*)malloc(size * sizeof(size_t));
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
