#include <ft_env_tool.h>
#include <ft_sub.h>
#include <stdlib.h>
#include <ft_exp_tool.h>

t_exp	*ft_exp_init(t_env *env)
{
	t_exp	*exp;
	t_env	*en;
	
	en = env;
	exp = NULL;
	if (!en)
		return (NULL);
	exp = ft_exp_new(ft_strdup(en->name), ft_strdup(en->data));
	en = en->next;
	while (en)
	{
		exp = ft_exp_join(exp, ft_strdup(en->name), ft_strdup(en->data));
		en = en->next;
	}
	return (exp);
}