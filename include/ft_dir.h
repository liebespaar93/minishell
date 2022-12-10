/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:50:55 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/10 15:23:36 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DIR_H
# define FT_DIR_H

int				ft_readdir_check_file(char *dir_name, char *file_name);
struct dirent	*ft_readdir_get_file(char *dir_name, char *file_name);

#endif
