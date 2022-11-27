/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:19:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/25 03:01:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_global.h>
#include <ft_export_tool.h>
#include <ft_error.h>

const char **ft_cpy_origin_envp(const char **envp)
{
	char	**tmp;
	int		i;

	i = 0;
	g_global->origin_envp = \
		malloc(sizeof(char *) * (ft_void_len((void **)envp) + 1));
	if (!g_global->origin_envp)
		exit(ft_stderror());
	tmp = (char **)envp;
	while (*tmp)
		g_global->origin_envp[i++] = *tmp++;
	g_global->origin_envp[i] = NULL;
	return (g_global->origin_envp);
}

t_global	*ft_global_init(const char **envp)
{
	g_global = (t_global *)malloc(sizeof(t_global));
	if (!g_global)
		exit(ft_stderror());
	g_global->life = 1;
	g_global->export_ptr = ft_export_init(envp);
	g_global->origin_envp = ft_cpy_origin_envp(envp);
	if (!ttyname(STDIN_FILENO))
		g_global->life = -1;
	return (g_global);
}

int	ft_find_origin_envp(char **ptr)
{
	char	**tmp;

	tmp = (char **)g_global->origin_envp;
	while (*tmp)
	{
		if (*tmp == *ptr)
			return (1);
		tmp++;
	}
	return (0);
}
