#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
