/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:53:44 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 10:09:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/syslimits.h>

#include <readline/readline.h>
#include <readline/history.h>

#include <ft_global.h>
#include <ft_readline.h>
#include <ft_tool.h>
#include <ft_terminal.h>


void	ft_child_readline(char *str, int fd_pipe[2])
{
	char	*rl_buffer;

	rl_buffer = NULL;
	close(fd_pipe[STDIN_FILENO]);
	ft_signal_unset();
	ft_tty_quit_off();
	rl_buffer = readline(str);
	ft_tty_quit_on();
	if (!rl_buffer)
		exit(-1);
	write(fd_pipe[STDOUT_FILENO], rl_buffer, ft_strlen(rl_buffer));
	free(rl_buffer);
	exit(0);
}

char	*ft_parent_readline(int fd_pipe[2])
{
	char	buff[ARG_MAX];
	int		stat;
	
	ft_bzero(buff, sizeof(char) * ARG_MAX);
	close(fd_pipe[STDOUT_FILENO]);
	read(fd_pipe[STDIN_FILENO], buff, ARG_MAX);
	wait(&stat);
	close(fd_pipe[STDIN_FILENO]);
	if (stat == 2)
		printf("\n");
	if (stat < 0)
		return (NULL);
	if (stat == 65280)
		return (ft_strdup("\x04"));
	return (ft_strdup(buff));
}

char	*ft_readline_fork(char *str)
{
	pid_t	pid;
	int		fd_pipe[2];
	char	*result;

	result = NULL;
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
		ft_child_readline(str, fd_pipe);
	else
		result = ft_parent_readline(fd_pipe);
	return (result);
}

void	ft_child_readline_ori(char *str, int fd_pipe[2])
{
	close(fd_pipe[STDIN_FILENO]);
	ft_signal_unset();
	ft_tty_quit_off();
	free(readline(str));
	ft_tty_quit_on();
	write(fd_pipe[STDOUT_FILENO], rl_line_buffer, ft_strlen(rl_line_buffer));
	exit(0);
}

char	*ft_readline_fork_ori(char *str)
{
	pid_t	pid;
	int		fd_pipe[2];
	char	*result;

	result = NULL;
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
		ft_child_readline_ori(str, fd_pipe);
	else
		result = ft_parent_readline(fd_pipe);
	return (result);
}