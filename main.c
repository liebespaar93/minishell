
#include <ft_command.h>
#include <ft_banner.h>
#include <stdio.h>



#include <ft_sub.h>
void ft_split_env(char *str, char **name, char **data)
{
	char	*temp;
	int		len;

	len = ft_strlen(str);
	temp = str;
	while (temp == '=')
		temp++;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	ft_printf_banner();
	ft_pwd();
	ft_cd("include");
	char **temp;
	temp = envp;
	while (*temp)
	{
		printf("%s\n", *temp);
		temp++;
	}
	ft_pwd();
	return (1);

}