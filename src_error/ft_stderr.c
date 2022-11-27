/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stderr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:50:42 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 16:35:53 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#include <ft_tool.h>
#include <ft_env_tool.h>

int	ft_stderror(void)
{
	char	buff[LINE_MAX];

	*buff = '\0';
	ft_strcat(buff, " ");
	ft_strcat(buff, strerror(errno));
	ft_strcat(buff, "\n");
	write(STDERR_FILENO, buff, ft_strlen(buff));
	close(STDERR_FILENO);
	return (errno);
}
