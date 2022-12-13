/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:59:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/14 04:31:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_cmd.h>
#include <ft_transrate.h>
#include <ft_exe.h>
#include <ft_env_tool.h>
#include <ft_export_tool.h>

void	ft_cmd_running(t_cmd *cmd, pid_t *pid, char *str, int *index)
{
	while (*str)
	{
		if (*str == '|' && str++)
		{
			cmd->std = 0;
			if (cmd->argv)
				ft_cmd_envset(cmd, cmd->std);
			pid[(*index)++] = ft_cmd_pipe(cmd);
			ft_argv_free(cmd);
			cmd->skip = 0;
		}
		else if (ft_strchr("<>", *str))
			str = ft_redirect(cmd, str);
		else if (ft_strchr(WHITE_SPACE, *str))
			str++;
		else
			str = ft_cmd_word(cmd, str);
		if (!str && ft_putenv_stat(1))
			return ;
	}
	if (cmd->argv)
		ft_cmd_envset(cmd, cmd->std);
	ft_putenv_stat(ft_cmd_std(cmd));
}

int	ft_cmd_set(char *str)
{
	t_cmd	cmd;
	pid_t	pid[MAX_CMD_LEN];
	int		fd[2];
	int		index;

	index = 0;
	fd[STDIN_FILENO] = dup(STDIN_FILENO);
	fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	ft_cmd_init(&cmd);
	ft_cmd_running(&cmd, pid, str, &index);
	if (index)
		ft_cmd_wait(pid, index);
	ft_argv_free(&cmd);
	dup2(fd[STDIN_FILENO], STDIN_FILENO);
	dup2(fd[STDOUT_FILENO], STDOUT_FILENO);
	close(fd[STDIN_FILENO]);
	close(fd[STDOUT_FILENO]);
	free(str);
	return (1);
}

int	ft_cmd(char *history_str)
{
	char	*temp;
	char	*start;

	start = history_str;
	temp = history_str;
	while (start)
	{
		if (!*temp)
			return (ft_cmd_set(ft_strncpy(start, temp - start)));
		else if (ft_strchr("\'\"", *temp))
			temp = ft_strchr(temp + 1, *temp) + 1;
		else if (*temp == ';' && ft_cmd_set(ft_strncpy(start, temp - start)))
			start = ++temp;
		else
			temp++;
	}
	return (1);
}
