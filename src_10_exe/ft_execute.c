/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 17:22:07 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <ft_cmd.h>
#include <ft_tool.h>
#include <ft_builtin.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>
#include <ft_file.h>
#include <ft_error.h>
#include <ft_readline.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int	ft_execute_dir(char *argv[])
{
	int			pid;
	int			stat;
	char		**envp;

	stat = ft_pwd_check(argv[0]);
	if (stat)
		return (stat);
	pid = fork();
	if (!pid)
	{
		ft_signal_unset();
		envp = ft_envp();
		if (execve(argv[0], argv, envp) < 0)
			stat = ft_stderror();
		ft_free_envp(&envp);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		exit(stat);
	}
	waitpid(pid, &stat, 0);
	return (ft_putenv_stat(stat / 256));
}

int	ft_execute_else(char *argv[])
{
	char		*temp;
	char		**envp;
	int			pid;
	int			stat;

	temp = ft_get_file(argv[0]);
	stat = 0;
	if (*temp)
	{
		pid = fork();
		if (!pid && !ft_signal_unset())
		{
			envp = ft_envp();
			if (execve(temp, argv, envp) < 0)
				ft_stderror();
			(close(STDIN_FILENO), close(STDOUT_FILENO), ft_free_envp(&envp));
			exit(errno);
		}
		(close(STDOUT_FILENO), waitpid(pid, &stat, 0));
	}
	else if (write(STDERR_FILENO, argv[0], strlen(argv[0])) && \
		write(STDERR_FILENO, " : command not found\n", 21))
		return (127);
	free(temp);
	return (ft_putenv_stat(stat / 256));
}

int	ft_set(int argc, const char *argv[])
{
	extern char	**environ;
	int			i;

	(void)argc;
	(void)argv;
	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

int	ft_execute(char *argv[])
{
	if (!argv[0])
		return (0);
	if (!ft_strcmp("echo", argv[0]))
		return (ft_echo(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("cd", argv[0]))
		return (ft_cd(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("pwd", argv[0]))
		return (ft_pwd());
	else if (!ft_strcmp("export", argv[0]))
		return (ft_export(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("unset", argv[0]))
		return (ft_unset(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("env", argv[0]))
		return (ft_env(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("exit", argv[0]))
		return (ft_exit(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("set", argv[0]))
		return (ft_set(ft_void_len((void **)argv), (const char **)argv));
	else if (ft_strchr(argv[0], '/'))
		return (ft_execute_dir(argv));
	else
		return (ft_execute_else(argv));
	return (0);
}
