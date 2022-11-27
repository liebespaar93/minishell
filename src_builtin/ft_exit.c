/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:17:49 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 16:40:50 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <ft_tool.h>
#include <ft_global.h>
#include <ft_env_tool.h>
#include <ft_global.h>

static void	check_str(char **s)
{
	char	*str;

	str = *s;
	while ((0x09 <= *str && *str <= 0x0d) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
		str++;
	*s = str;
}

int	ft_exit(int argc, const char *argv[])
{
	char		*str;
	long long	i;

	if (g_global->life != -1)
		printf("exit\n");
	g_global->life = 0;
	if (argc > 2 && write(STDERR_FILENO, " too many arguments", 19))
		return (1);
	if (argv[1])
	{
		str = (char *)argv[1];
		i = ft_atoi(argv[1]);
		check_str(&str);
		while (ft_isdigit(*str))
			str++;
		if (*str || (ft_strlen(argv[1]) > 2 && (i == -1 || i == 0)))
		{
			write(STDERR_FILENO, " numeric argument required", 26);
			i = 255;
		}
		return (i %= 256);
	}
	return (0);
}
