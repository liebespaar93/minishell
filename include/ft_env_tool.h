#ifndef FT_ENV_TOOL_H
# define FT_ENV_TOOL_H

typedef struct s_env	t_env;

typedef struct s_env
{
	char	*name;
	char	*data;
	t_env	*next;
	t_env	*prev;
}	t_env;



/* ft_env_new */

t_env	*ft_env_new(char *name, char *data);
t_env	*ft_env_add(t_env *head, t_env *new);
t_env	*ft_env_join(t_env **head, char *name, char *data);


/* ft_env_search */

t_env	*ft_env_name(t_env *head, char *str);
char	*ft_env_data(t_env *head, char *str);

/* ft_env_del */
int	ft_env_del(t_env **head, t_env *target);

/* ft_env_init */
t_env	*ft_env_init(char ***envp);

#endif
