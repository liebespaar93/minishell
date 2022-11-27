/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:39:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/25 11:46:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include <ft_error.h>
#include <ft_tool.h>

int	ft_pwd(void)
{
	char	buf[PATH_MAX + 1];

	if (getcwd(buf, PATH_MAX) == NULL)
	{
		ft_stderror();
		return (0);
	}
	ft_strcat(buf, "\n");
	write(STDOUT_FILENO, buf, strlen(buf));
	return (0);
}
