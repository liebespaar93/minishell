/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_readline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:51:17 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/09 16:12:07 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <ft_readline.h>
#include <ft_tool.h>

int	ft_redirect_readline(char *file_name, int file)
{
	char	*temp;

	while (1)
	{
		temp = ft_readline_fork_ori("> ");
		if (!*temp && ft_free((void **)&temp))
			return (0);
		else if (*temp == '\x04' && ft_free((void **)&temp))
			return (0);
		if (!ft_strncmp(temp, file_name, ft_strlen(file_name)) && \
			!*(temp + ft_strlen(file_name) + 1))
			break ;
		write(file, temp, ft_strlen(temp));
		free(temp);
	}
	return (1);
}
