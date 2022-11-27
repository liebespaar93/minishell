/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:19:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 09:57:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

char	*ft_readline_fork(char *str);
char	*ft_readline_fork_ori(char *str);

int		ft_signal_set(void);
int		ft_signal_unset(void);
void	ft_sigint(int signo);
void	ft_sigpipe(int signo);
#endif