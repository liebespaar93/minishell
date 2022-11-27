/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:31:00 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/24 20:19:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMD_H
# define FT_CMD_H

# define MAX_CMD_LEN 200

typedef struct s_cmd
{
	char	**argv;
	int		fd_in;
	int		fd_out;
	int		skip;
}	t_cmd;

int		ft_cmd(char *str);

char	**ft_argv_add(t_cmd *cmd, char *str);
void	ft_argv_free(t_cmd *cmd);

char	*ft_redirect(t_cmd *cmd, char *str);

/* ft_cmd_tool */

t_cmd	*ft_cmd_init(t_cmd *cmd);
char	*ft_cmd_word(t_cmd *cmd, char *str);
void	ft_cmd_envset(t_cmd *cmd, int std);
void	ft_cmd_wait(pid_t *pid, int index);
#endif