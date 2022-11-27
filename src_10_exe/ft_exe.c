/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 16:39:10 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <ft_cmd.h>
#include <ft_tool.h>
#include <ft_builtin.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>
#include <ft_exe.h>

#include <stdio.h>

int	ft_exe(t_cmd *cmd)
{
	dup2(cmd->fd_in, STDIN_FILENO);
	dup2(cmd->fd_out, STDOUT_FILENO);
	if (cmd->skip)
		return (1);
	if (!cmd->argv)
		return (0);
	return (ft_execute(cmd->argv));
}
