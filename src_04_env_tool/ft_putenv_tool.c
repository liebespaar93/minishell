/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:24 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/23 03:23:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_tool.h>
#include <ft_env_tool.h>

int	ft_putenv_stat(int num)
{
	char	*str_num;
	char	*str;

	str_num = ft_itoa(num);
	str = ft_strjoin("?=", str_num);
	ft_putenv((const char *)str);
	free(str_num);
	return (num);
}