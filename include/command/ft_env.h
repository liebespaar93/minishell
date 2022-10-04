#ifndef FT_ENV_H
# define FT_ENV_H

typedef struct s_env	t_env;

typedef struct s_env
{
	char	*name;
	char	*data;
	t_env	*next;
	t_env	*prev;
}	t_env;

t_env	*ft_env_new(char *name, char *data);
t_env	*ft_env_add(t_env *head, t_env *new);
t_env	*ft_env(t_env **head, char *name, char *data);
void	ft_env_list(t_env *head);
t_env	*ft_env_find(t_env *head, char *str);
char	*ft_env_data(t_env *head, char *str);
int		ft_env_del(t_env **head, t_env *target);
#endif
