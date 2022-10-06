
#include <ft_sub.h>
#include <stdlib.h>
#include <ft_exp_tool.h>

t_exp *ft_exp_new(char *name, char *data)
{
	t_exp *new;

	if (!ft_malloc((void **)&new, sizeof(t_exp)))
		return (NULL);
	new->name = name;
	new->data = data;
	return (new);
}

t_exp	*ft_exp_add(t_exp *head, t_exp *exp)
{
	if (!head)
		return (exp);
	if (!exp)
		return (head);
	if (head->next)
		exp->next = head->next;
	head->next = exp;
	exp->prev = head;
	return (exp);
}

#include <stdio.h>
t_exp	*ft_exp_join(t_exp *exp, char *name, char *data)
{
	t_exp	*temp;

	if (!exp)
		return (ft_exp_new(name, data));
	if (ft_strcmp(exp->name, name) > 0)
	{
		ft_exp_add(ft_exp_new(name, data), exp);
		return (exp->prev);
	}
	temp = exp;
	while (temp->next)
	{
		temp = temp->next;
		if (ft_strcmp(temp->name, name) == 0)
		{
			free(temp->data);
			free(name);
			temp->data = data;
			return (exp);
		}
		else if (ft_strcmp(temp->name, name) > 0)
		{
			ft_exp_add(temp->prev, ft_exp_new(name, data));
			return (exp);
		}
	}
	if (!temp->next)
		ft_exp_add(temp, ft_exp_new(name, data));
	return (exp);
}
