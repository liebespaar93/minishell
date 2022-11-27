/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:22:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 11:15:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <ft_tool.h>
#include <ft_terminal.h>
#include <ft_global.h>
#include <ft_env_tool.h>

int	main(int argc, char *argv[], const char *envp[])
{
	struct termios	oldtty;
	struct termios	newtty;

	(void)argc;
	(void)argv;
	ft_global_init(envp);
	g_global->origin_envp_ptr = envp;
	tcgetattr(STDIN_FILENO, &oldtty);
	ft_bzero(&newtty, sizeof(struct termios));
	ft_bash_ttyset(&newtty);
	tcsetattr(STDIN_FILENO, TCSANOW, &newtty);
	ft_putenv(ft_strdup("?=0"));
	ft_tty_loop();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldtty);
	return (ft_atoi(getenv("?")));
}
