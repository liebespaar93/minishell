#include <stdlib.h>
#include <ft_exp_tool.h>

t_exp	*ft_exp_del(t_exp *exp)
{
	t_exp	*next;
	t_exp	*prev;

	if (!exp)
		return (NULL);
	next = exp->next;
	prev = exp->prev;
	next->prev = prev;
	prev->next = next;
	free(exp->name);
	free(exp->data);
	free(exp);
	if (next)
		return (next);
	return (prev);
}