/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_in_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:00 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 15:21:49 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

#include <ft_tool.h>

int	ft_readdir_check_file(char *dir_name, char *file_name)
{
	DIR				*dir;
	struct dirent	*file;
	int				stat;

	dir = opendir(dir_name);
	file = NULL;
	stat = 0;
	while (dir)
	{
		file = readdir(dir);
		if (!file || !ft_strcmp(file->d_name, file_name))
			break ;
	}
	if (!file && write(STDERR_FILENO, " No such file or directory\n", 27))
		stat = 127;
	else if (file->d_type == 4 && write(STDERR_FILENO, " is a directory\n", 16))
		stat = 126;
	if (dir)
		closedir(dir);
	return (stat);
}

struct dirent	*ft_readdir_get_file(char *dir_name, char *file_name)
{
	DIR				*dir;
	struct dirent	*file;

	dir = opendir(dir_name);
	file = NULL;
	while (dir)
	{
		file = readdir(dir);
		if (!file)
			break ;
		if (!ft_strcmp(file->d_name, file_name) && !closedir(dir))
			return (file);
	}
	if (dir)
		closedir(dir);
	return (file);
}
