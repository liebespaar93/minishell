#ifndef FT_EXP_TOOL_H
# define FT_EXP_TOOL_H

# include <ft_env_tool.h>

typedef struct s_exp	t_exp;

typedef struct s_exp
{
	char	*name;
	char	*data;
	t_exp	*next;
	t_exp	*prev;
}	t_exp;


t_exp	*ft_exp_new(char *name, char *data);
t_exp	*ft_exp_add(t_exp *head, t_exp *exp);
t_exp	*ft_exp_del(t_exp *exp);
t_exp	*ft_exp_join(t_exp *exp, char *name, char *data);

t_exp	*ft_exp_init(t_env *env);

#endif
