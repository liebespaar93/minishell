
#include <ft_command.h>
#include <ft_banner.h>
#include <stdio.h>



#include <ft_sub.h>

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	t_exp	*exp;

	ft_printf_banner();
	ft_pwd();
	ft_cd("include");
	ft_pwd();
	env = ft_env_init(&envp);
	ft_env(env);
	exp = ft_exp_init(env);
	ft_export(exp);
	return (1);
}