#include <stdlib.h>
#include <stdio.h>

#include <ft_env.h>
#include <ft_sub.h>
#include <ft_color.h>

t_env	*ft_env_new(char *name, char *data)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = name;
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env	*ft_env_add(t_env *head, t_env *env)
{
	t_env	*temp;

	temp = head;
	if (!temp)
	{
		head = env;
		return (env);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = env;
	env->prev = temp;
	return (env);
}

t_env	*ft_env_join(t_env **head, char *name, char *data)
{
	t_env	*temp;

	temp = *head;
	if (!temp)
	{
		*head = ft_env_new(name, data);
		return (*head);
	}
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
		{
			free(temp->data);
			free(name);
			temp->data = data;
			return (temp);
		}
		temp = temp->next;
	}
	ft_env_add(temp, ft_env_new(name, data));
	return (temp);
}
