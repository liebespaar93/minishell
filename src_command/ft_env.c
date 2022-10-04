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

t_env	*ft_env_add(t_env *head, t_env *new)
{
	t_env	*temp;

	temp = head;
	if (!temp)
	{
		head = new;
		return (new);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (new);
}

t_env	*ft_env(t_env **head, char *name, char *data)
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

void	ft_env_list(t_env *head)
{
	t_env	*temp;

	temp = head;
	while (temp)
	{
		printf(FG_LYELLOW"%s",temp->name);
		printf(FG_LGREY"=");
		printf(FG_LGREEN"%s"NO_COLOR,temp->data);
		temp = temp->next;
	}
}

t_env	*ft_env_find(t_env *head, char *str)
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

int	ft_env_del(t_env **head, t_env *target)
{
	if (!(*head))
		return (-1);
	if (!target)
		return (-2);
	if ((*head) == target)
		(*head) = (*head)->next;
	if (target->prev)
		target->prev->next = target->next;
	if (target->next)
		target->next->prev = target->prev;
	free(target->name);
	free(target->data);
	free(target);
	return (0);
}