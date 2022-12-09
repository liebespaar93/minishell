/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:00:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/09 14:50:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <ft_tool.h>
#include <ft_cmd.h>
#include <ft_error.h>
#include <ft_env_tool.h>

char	*ft_redirect_in(char *str, char **file_name_ptr, t_cmd *cmd)
{
	int		file;
	char	*file_name;

	file_name = ft_file_name(&str);
	*file_name_ptr = file_name;
	if (!*file_name)
		return (str);
	file = open(file_name, O_RDONLY);
	if (file == -1 && ft_stderror())
	{
		cmd->skip = 1;
		return (ft_strchr(str, '|'));
	}
	cmd->fd_in = file;
	return (str);
}

char	*ft_redirect_d_in(char *str, char **file_name_ptr, t_cmd *cmd)
{
	int		file;
	char	*file_name;

	file_name = ft_file_name(&str);
	*file_name_ptr = file_name;
	if (!*file_name)
		return (str);
	file = open("redirect", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1 && ft_stderror())
		return (ft_strchr(str, '|'));
	if (!ft_redirect_readline(file_name, file))
	{
		close(file);
		return ("");
	}
	close(file);
	file = open("redirect", O_RDONLY);
	if (file == -1 && ft_stderror())
		return (ft_strchr(str, '|'));
	cmd->fd_in = file;
	return (str);
}

char	*ft_redirect_d_out(char *str, char **file_name_ptr, t_cmd *cmd)
{
	int		file;
	char	*file_name;

	file_name = ft_file_name(&str);
	*file_name_ptr = file_name;
	if (!*file_name)
		return (str);
	file = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0777);
	if (file == -1 && ft_stderror())
		return (ft_strchr(str, '|'));
	cmd->fd_out = file;
	return (str);
}

char	*ft_redirect_out(char *str, char **file_name_ptr, t_cmd *cmd)
{
	int		file;
	char	*file_name;

	file_name = ft_file_name(&str);
	*file_name_ptr = file_name;
	if (!*file_name)
		return (str);
	file = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1 && ft_stderror())
		return (ft_strchr(str, '|'));
	cmd->fd_out = file;
	return (str);
}

char	*ft_redirect(t_cmd *cmd, char *str)
{
	char	*file_name;
	char	*temp;

	temp = str;
	file_name = NULL;
	if (!ft_strncmp("<", str, 1) && temp++)
	{
		if (cmd->fd_in != STDIN_FILENO && !close(cmd->fd_in))
			cmd->fd_in = STDIN_FILENO;
		if (!ft_strncmp("<<", temp - 1, 2) && temp++)
			temp = ft_redirect_d_in(temp, &file_name, cmd);
		else
			temp = ft_redirect_in(temp, &file_name, cmd);
	}
	else if (!ft_strncmp(">", temp, 1) && temp++)
	{
		if (cmd->fd_out != STDOUT_FILENO && !close(cmd->fd_out))
			cmd->fd_out = STDOUT_FILENO;
		if (!ft_strncmp(">>", temp - 1, 2) && temp++)
			temp = ft_redirect_d_out(temp, &file_name, cmd);
		else
			temp = ft_redirect_out(temp, &file_name, cmd);
	}
	free(file_name);
	return (temp);
}
