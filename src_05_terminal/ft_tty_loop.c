/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tty_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:55:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/09 17:00:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/syslimits.h>

#include <ft_tool.h>
#include <ft_running.h>
#include <ft_readline.h>
#include <ft_global.h>

void	ft_tty_loop(void)
{
	char	history_str[ARG_MAX];
	char	*temp;

	ft_bzero(history_str, sizeof(char [ARG_MAX]));
	ft_signal_set();
	while (g_global->life)
	{
		temp = NULL;
		ft_bzero(history_str, sizeof(char [ARG_MAX]));
		temp = ft_readline_fork("minishell-v1.0$ ");
		if (!*temp)
			continue ;
		if (*temp == '\x04' && ft_strcat(history_str, "exit ") \
			&& printf("\b\b"))
			ft_strcat(history_str, getenv("?"));
		else
			ft_strcat(history_str, temp);
		free(temp);
		if (*history_str)
			(ft_running(history_str), add_history(history_str));
	}
	ft_signal_unset();
}
