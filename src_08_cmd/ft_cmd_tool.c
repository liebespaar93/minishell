/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:04:39 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/09 21:03:19 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_cmd.h>
#include <ft_transrate.h>
#include <ft_env_tool.h>

t_cmd	*ft_cmd_init(t_cmd *cmd)
{
	cmd->argv = NULL;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->skip = 0;
	cmd->std = 1;
	return (cmd);
}

char	*ft_cmd_word(t_cmd *cmd, char *str)
{
	char	*temp;
	char	*argv;
	char	*word;

	temp = str;
	while (*temp && !ft_strchr(WHITE_SPACE, *temp) && !ft_strchr("<>|", *temp))
	{
		if (ft_strchr("\'\"", *temp))
			temp = ft_strchr(temp + 1, *temp);
		temp++;
	}
	argv = ft_strncpy(str, temp - str);
	word = ft_transrate_env(argv);
	if (!*word)
		free(word);
	else
		ft_argv_add(cmd, word);
	free(argv);
	return (temp);
}

void	ft_cmd_envset(t_cmd *cmd, int std)
{
	char	*temp;
	int		index;
	int		i;

	index = 0;
	while (cmd->argv[index])
	{
		temp = cmd->argv[index];
		while (ft_isalpha(*temp) || ft_isdigit(*temp) || *temp == '_')
			temp++;
		if (*temp != '=')
			break ;
		index++;
	}
	while (index)
	{
		i = 0;
		if (!cmd->argv[index--] && std)
			ft_putenv(cmd->argv[0]);
		else
			free(cmd->argv[0]);
		while (cmd->argv[i++])
			cmd->argv[i - 1] = cmd->argv[i];
	}
}

void	ft_cmd_wait(pid_t *pid, int index)
{
	int		std;
	int		i;

	if (index == 0)
		return ;
	i = 0;
	while (i < index)
	{
		waitpid(pid[i], &std, 0);
		i++;
	}
}
