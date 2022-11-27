/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:50:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/27 16:32:38 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_tool.h>
#include <ft_transrate.h>

#include <stdio.h>

char	*ft_file_name(char **str)
{
	char	*word;
	char	*temp;
	char	*file_name;
	char	*trans_name;

	temp = *str;
	while (*temp && ft_strchr(WHITE_SPACE, *temp))
		temp++;
	word = temp;
	while (*temp)
	{
		if (ft_strchr("\'\"", *temp))
			temp = ft_strchr(temp + 1, *temp) + 1;
		else if (!ft_strchr(WHITE_SPACE, *temp) && !ft_strchr("|;", *temp))
			temp++;
		else
			break ;
	}
	file_name = ft_strncpy(word, temp - word);
	trans_name = ft_transrate_env(file_name);
	free(file_name);
	*str = temp;
	return (trans_name);
}
