/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:24:38 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 17:08:17 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>

int	ft_env_print(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		if (ft_export_find(environ[i]))
			printf("%s\n", environ[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_env(int argc, const char *argv[])
{
	int		i;

	if (argc == 1)
		ft_env_print();
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (!ft_strchr(argv[i], '=') || *argv[i] == '=')
				break ;
			ft_export_set((char *)argv[i]);
		}
		ft_env_print();
		while (i-- > 1)
		{
			ft_unsetenv(*ft_export_find((char *)argv[i]));
			ft_export_unset((char *)argv[i]);
		}
	}
	ft_putenv_stat(0);
	return (0);
}
