/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:58:44 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 15:05:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GLOBAL_H
# define FT_GLOBAL_H

# include <termios.h>

typedef struct s_global
{
	int				life;
	const char		**export_ptr;
	const char		**origin_envp_ptr;
	const char		**origin_envp;
	void			*old_ft_sigint;
	void			*old_ft_sigquit;
}	t_global;

t_global	*g_global;

t_global	*ft_global_init(const char **envp);
int			ft_find_origin_envp(char **ptr);

#endif