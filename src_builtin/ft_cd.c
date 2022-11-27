/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:44:45 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/25 11:56:13 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#include <ft_tool.h>
#include <ft_env_tool.h>
#include <ft_error.h>

int	ft_cd(int argc, const char *argv[])
{
	int			ret;
	char		buf[NAME_MAX];
	const char	*target;

	(void)argc;
	target = argv[1];
	if (!ft_strcmp(argv[1], "~"))
		target = getenv("HOME");
	if (!ft_strcmp(argv[1], "-"))
		target = getenv("OLDPWD");
	ret = chdir(target);
	if (ret != 0)
	{
		ft_stderror();
		return (ft_putenv_stat(1));
	}
	if (getcwd(buf, 1024) == NULL)
	{
		ft_stderror();
		return (ft_putenv_stat(1));
	}
	ft_putenv(ft_strjoin("OLDPWD=", getenv("PWD")));
	ft_putenv(ft_strjoin("PWD=", buf));
	return (0);
}
