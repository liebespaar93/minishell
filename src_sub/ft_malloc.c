#include <stdlib.h>


int	ft_malloc(void **ptr, size_t size)
{
	char *new;

	new = malloc(size);
	if (!new)
		return (0);
	while (size--)
		new[size] = 0;
	*ptr = new;
	return (1);
}