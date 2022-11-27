/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:24:42 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 16:35:30 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <ft_tool.h>
#include <ft_global.h>

void	ft_sigint(int signo)
{
	(void)signo;
	return ;
}

void	ft_sigquit(int signo)
{
	(void)signo;
	return ;
}

int	ft_signal_set(void)
{
	g_global->old_ft_sigint = signal(SIGINT, ft_sigint);
	g_global->old_ft_sigquit = signal(SIGQUIT, ft_sigquit);
	return (0);
}

int	ft_signal_unset(void)
{
	signal(SIGINT, g_global->old_ft_sigint);
	signal(SIGINT, g_global->old_ft_sigquit);
	return (0);
}
