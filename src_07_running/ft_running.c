/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:22:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 16:40:52 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/syslimits.h>

#include <ft_tool.h>
#include <ft_terminal.h>
#include <ft_cmd.h>
#include <ft_error.h>
#include <ft_readline.h>

char	*ft_while_eof(char *history_str, char *str, int *flag)
{
	char	*temp;

	ft_strcat(history_str, "\n");
	while (!ft_strchr(str + 1, *str))
	{
		temp = ft_readline_fork_ori("> ");
		if (!*temp && ft_free((void **)&temp))
			return (NULL);
		else if (*temp == '\x04' && ft_free((void **)&temp))
		{
			printf("\b\b unexpected EOF while looking for matching `%c'\n", *str);
			ft_syntax_error((int [1]){3}, NULL);
			return (NULL);
		}
		ft_strcat(history_str, temp);
		free(temp);
	}
	*flag = 0;
	return (ft_strchr(str + 1, *str) + 1);
}

char	*ft_pipe_eof(char *history_str, char *str)
{
	char	*temp;

	ft_strcat(history_str, " ");
	while (!*str || ft_strchr(WHITE_SPACE, *str))
	{
		if (!*str)
		{
			temp = ft_readline_fork("> ");
			if (!*temp && ft_free((void **)&temp))
				return (NULL);
			else if (*temp == '\x04' && ft_free((void **)&temp))
			{
				ft_syntax_error((int [1]){3}, NULL);
				return (NULL);
			}
			ft_strcat(history_str, temp);
			free(temp);
		}
		else
			str++;
	}
	return (str);
}

char	*ft_redirect_eof(char *str, int *flag)
{
	char	*temp;

	if (!ft_strncmp(">>", str, 2))
		str += 2;
	else if (!ft_strncmp("<<", str, 2))
		str += 2;
	else if (!ft_strncmp(">", str, 1))
		str += 1;
	else if (!ft_strncmp("<", str, 1))
		str += 1;
	temp = str;
	while (*temp)
	{
		if (!ft_strchr(WHITE_SPACE, *temp))
			break ;
		temp++;
	}
	if (!*temp && ft_syntax_error(flag, "\n"))
		return (NULL);
	return (str);
}

char	*ft_semi_eof(char *str, int *flag)
{
	char	*temp;

	temp = str + 1;
	while (*temp && ft_strchr(WHITE_SPACE, *temp))
		temp++;
	*flag = 1;
	return (str + 1);
}

int	ft_running(char *history_str)
{
	char	*temp;
	int		flag;

	flag = 1;
	temp = history_str;
	while (*temp)
	{
		if (ft_strchr("\'\"", *temp))
			temp = ft_while_eof(history_str, temp, &flag);
		else if (*temp == '|' && !ft_syntax_error(&flag, temp))
			temp = ft_pipe_eof(history_str, temp + 1);
		else if (ft_strchr("<>",*temp) && !ft_syntax_error(&flag, temp))
			temp = ft_redirect_eof(temp, &flag);
		else if (*temp == ';' && !ft_syntax_error(&flag, temp))
			temp = ft_semi_eof(temp, &flag);
		else if (flag < 0)
			return (flag);
		else if (!ft_strchr(WHITE_SPACE, *temp++))
			flag = 0;
		if (!temp)
			break ;
		if (!*temp)
			ft_cmd(history_str);
	}
	return (0);
}
