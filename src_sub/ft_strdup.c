#include <stdlib.h>

char	*ft_strdup(const char* str)
{
	char *new;
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}