/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:14:37 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 16:40:25 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <ft_error.h>
#include <ft_tool.h>
#include <ft_env_tool.h>

char	*ft_syntax_word(char *str)
{
	if (!ft_strncmp(">>", str, 2))
		return (">>");
	else if (!ft_strncmp("<<", str, 2))
		return ("<<");
	else if (!ft_strncmp("<>", str, 2))
		return ("<>");
	else if (!ft_strncmp(">", str, 1))
		return (">");
	else if (!ft_strncmp("<", str, 2))
		return ("<");
	else if (!ft_strncmp(";", str, 1))
		return (";");
	else if (!ft_strncmp("|", str, 1))
		return ("|");
	else if (!ft_strncmp("\n", str, 1))
		return ("newline");
	return (NULL);
}

int	ft_syntax_error(int *flag, char *s)
{
	char	*word;

	if (*flag == 3 && printf(" syntax error: unexpected end of file\n"))
		return (ft_putenv_stat(ERROR_SYNTAX));
	word = ft_syntax_word(s);
	if (!word)
		return (0);
	if (*flag == 1 && !ft_strchr("<>", *word))
	{
		printf(" syntax error near unexpected token `%s'\n", word);
		*flag = -1;
		return (ft_putenv_stat(ERROR_SYNTAX));
	}
	else if (*flag == 2)
	{
		printf(" syntax error near unexpected token `%s'\n", word);
		*flag = -1;
		return (ft_putenv_stat(ERROR_SYNTAX));
	}
	if (ft_strchr(";|", *word))
		*flag = 1;
	else
		*flag = 2;
	return (0);
}
