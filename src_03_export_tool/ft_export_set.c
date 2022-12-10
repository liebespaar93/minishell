/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:36:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 18:14:06 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_tool.h>
#include <ft_global.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>

void	ft_export_cpy(const char **export, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		export[i] = g_global->export_ptr[i];
		i++;
	}
}

int	ft_export_set(char *name)
{
	const char	**export;
	int			len;

	if (ft_strchr(name, '='))
		ft_putenv(ft_strdup(name));
	if (ft_export_find(name))
		return (0);
	len = ft_void_len((void **)g_global->export_ptr);
	export = (const char **)malloc(sizeof(char *) * (len + 2));
	if (!export)
		return (-1);
	ft_export_cpy(export, len);
	export[len] = ft_strword(name);
	export[len + 1] = NULL;
	free(g_global->export_ptr);
	g_global->export_ptr = export;
	return (0);
}
