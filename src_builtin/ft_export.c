/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:23:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 03:45:20 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>

int	ft_export_check(const char *str)
{
	char	*temp;

	temp = (char *)str;
	if (!(ft_isalpha(*temp) || *temp == '_'))
		return (1);
	temp++;
	while (*temp && *temp != '=')
	{
		if (!(ft_isalpha(*temp) || *temp == '_' || ft_isdigit(*temp)))
			return (1);
		temp ++;
	}
	return (0);
}

int	ft_export(int argc, const char *argv[])
{
	int	i;
	int	flag;

	flag = 0;
	if (argc == 1)
		ft_export_args();
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (ft_export_check(argv[i]))
			{
				write(STDERR_FILENO, " not a valid identifier\n", 24);
				ft_putenv_stat(1);
				flag = 1;
			}
			else
				ft_export_set((char *)argv[i]);
		}
	}
	return (flag);
}
