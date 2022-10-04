#include <stdlib.h>
#include <stdio.h>

#include <ft_env.h>
#include <ft_sub.h>
#include <ft_color.h>

t_env	*ft_env_name(t_env *head, char *str)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		if (!ft_strcmp(temp->name, str))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

char	*ft_env_data(t_env *head, char *str)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		if (!ft_strcmp(temp->name, str))
			return (temp->data);
		temp = temp->next;
	}
	return (NULL);
}
