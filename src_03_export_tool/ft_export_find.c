/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:40:26 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 03:54:35 by sunhwang         ###   ########.fr       */
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
	while (export[i])
	{
		if (!ft_strcmp(export[i], find))
		{
			free(find);
			return (&export[i]);
		}
		i++;
	}
	free(find);
	return (NULL);
}
