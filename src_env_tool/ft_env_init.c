#include <stdlib.h>
#include <stdio.h>

#include <ft_env.h>
#include <ft_sub.h>
#include <ft_color.h>


int ft_split_env(char *str, char **name, char **data)
{
	char	*temp;
	int		name_len;
	int		data_len;

	name_len = 0;
	data_len = 0;
	temp = str;
	if (!str)
		return (0);
	while (++name_len && *temp != '=')
		temp++;
	data_len = ft_strlen(temp);
	if (!ft_malloc((void **)name, name_len))
		return (0);
	if (!ft_malloc((void **)data, data_len))
	{
		free(name);
		return (0);
	}
	ft_memcpy(*name, str, name_len - 1);
	ft_memcpy(*data, temp + 1, data_len - 1);
	return (1);
}



t_env	*ft_env_init(char ***envp)
{
	t_env	*head;
	char	*name;
	char	*data;
	int		i;

	i = 0;
	head = NULL;
	while (ft_split_env((*envp)[i], &name, &data))
	{
		head = ft_env_add(head, ft_env_new(name, data));
		i++;
	}
	if (!head)
		return (NULL);
	while (head->prev)
		head = head->prev;
	ft_env(head);
	return (head);
}