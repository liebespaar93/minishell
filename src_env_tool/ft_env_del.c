#include <stdlib.h>
#include <stdio.h>

#include <ft_env.h>
#include <ft_sub.h>
#include <ft_color.h>

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