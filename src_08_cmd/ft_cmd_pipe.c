/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:37:04 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/09 23:17:55 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_cmd.h>
#include <ft_transrate.h>
#include <ft_exe.h>
#include <ft_export_tool.h>

void	ft_cmd_pipe_fd_close(t_cmd *cmd)
{
	if (cmd->fd_in != STDIN_FILENO && !close(cmd->fd_in))
		cmd->fd_in = STDIN_FILENO;
	if (cmd->fd_out != STDOUT_FILENO && !close(cmd->fd_out))
		cmd->fd_out = STDOUT_FILENO;
}

pid_t	ft_cmd_pipe(t_cmd *cmd)
{
	pid_t	pid;
	int		fd_pipe[2];
	int		stat;

	pipe(fd_pipe);
	pid = fork();
	if (!pid)
	{
		close(fd_pipe[STDIN_FILENO]);
		if (cmd->fd_out != STDOUT_FILENO)
			close(fd_pipe[STDOUT_FILENO]);
		else
			cmd->fd_out = fd_pipe[STDOUT_FILENO];
		stat = 256;
		if (!cmd->skip)
			stat = ft_exe(cmd);
		(close(fd_pipe[STDOUT_FILENO]), close(cmd->fd_in), close(cmd->fd_out));
		exit(stat / 256);
	}
	close(fd_pipe[STDOUT_FILENO]);
	ft_cmd_pipe_fd_close(cmd);
	cmd->fd_in = fd_pipe[STDIN_FILENO];
	return (pid);
}

int	ft_cmd_std(t_cmd *cmd)
{
	int	stat;

	stat = ft_exe(cmd);
	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	if (cmd->fd_out != STDOUT_FILENO)
		close(cmd->fd_out);
	return (stat);
}
