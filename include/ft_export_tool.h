/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_tool.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:42:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 15:06:47 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPORT_TOOL_H
# define FT_EXPORT_TOOL_H

char		**ft_envp(void);
char		**ft_free_envp(char ***envp_ptr);

const char	**ft_export_init(const char *envp[]);
const char	**ft_export_find(char *name);
int			ft_export_set(char *name);
int			ft_export_unset(char *name);
int			ft_export_args(void);

#endif