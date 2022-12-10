/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:59:23 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 16:08:27 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

#include <ft_tool.h>
#include <ft_env_tool.h>
#include <ft_dir.h>
#include <ft_file.h>

char	*ft_file_pwd(char *str)
{
	char		file_pwd[FILENAME_MAX];

	ft_bzero(file_pwd, sizeof(FILENAME_MAX));
	if (!ft_strncmp(str, "./", 2))
	{
		ft_strcat(file_pwd, getenv("PWD"));
		ft_strcat(file_pwd, str + 1);
	}
	else if (!ft_strncmp(str, "~/", 2))
	{
		ft_strcat(file_pwd, getenv("HOME"));
		ft_strcat(file_pwd, str + 1);
	}
	else
		ft_strcat(file_pwd, str);
	return (ft_strdup(file_pwd));
}

char	*ft_file_pwd_name(char *str)
{
	char	*file_name;

	file_name = str;
	while (ft_strchr(file_name + 1, '/'))
		file_name = ft_strchr(file_name + 1, '/');
	return (ft_strdup(file_name + 1));
}

char	*ft_file_pwd_dir(char *str)
{
	char	*dir_name;
	char	*file_name;

	file_name = ft_file_pwd_name(str);
	dir_name = ft_strncpy(str, ft_strlen(str) - ft_strlen(file_name));
	free(file_name);
	return (dir_name);
}

int	ft_stat(char *file)
{
	struct stat	buf;

	stat(file, &buf);
	if (buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
		return (1);
	write(STDERR_FILENO, " Permission denied\n", 19);
	return (0);
}

int	ft_pwd_check(char *str)
{
	char	*file_pwd;
	char	*file_dir;
	char	*file_name;
	int		fd;
	int		stat;

	file_pwd = ft_file_pwd(str);
	file_dir = ft_file_pwd_dir(file_pwd);
	file_name = ft_file_pwd_name(file_pwd);
	fd = open(file_dir, O_RDONLY | O_DIRECTORY);
	if (fd == -1 && write(STDERR_FILENO, " No such file or directory\n", 27))
		return (127);
	stat = ft_readdir_check_file(file_dir, file_name);
	if (stat && !close(fd))
		return (stat);
	close(fd);
	if (!ft_stat(file_pwd))
		return (126);
	fd = open(str, O_RDONLY);
	if (fd == -1 && write(STDERR_FILENO, " No such file or directory\n", 27))
		return (126);
	close(fd);
	return (stat);
}
