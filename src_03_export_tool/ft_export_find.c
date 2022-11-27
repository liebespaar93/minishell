/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:40:26 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/24 16:27:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_tool.h>
#include <ft_global.h>
#include <ft_env_tool.h>

const char	**ft_export_find(char *name)
{
	const char	**export;
	char		*find;
	int			i;

	i = 0;
	if (ft_strchr(name, '='))
		find = ft_strncpy(name, ft_strchr(name, '=') - name);
	else
		find = ft_strdup(name);
	export = g_global->export_ptr;
	(void)i;
	(void)export;
	while (export[i])
	{
		if (!ft_strcmp(export[i], find))
		{
			free(find);
			return (export);
		}
		i++;
	}
	free(find);
	return (NULL);
}
