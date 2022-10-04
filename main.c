
#include <ft_command.h>
#include <ft_banner.h>
#include <stdio.h>



#include <ft_sub.h>
int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	ft_printf_banner();
	ft_pwd();
	ft_cd("include");
	// char **temp;
	// temp = envp;
	// while (*temp)
	// {
	// 	printf("%s\n", *temp);
	// 	temp++;
	// }
	ft_pwd();
	ft_env_init(&envp);
	return (1);

}