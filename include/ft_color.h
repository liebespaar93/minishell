/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:51:47 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/15 12:28:55 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

/////***** foreground *****/////
# define FG				"\033[38;5;"
# define FG_BLACK		"\033[30m"
# define FG_RED			"\033[31m"
# define FG_GREEN		"\033[32m"
# define FG_YELLOW		"\033[33m"
# define FG_BLUE		"\033[34m"
# define FG_MAGENTA		"\033[35m"
# define FG_CYAN		"\033[36m"
# define FG_LGREY		"\033[37m"
# define FG_DGREY		"\033[90m"
# define FG_LRED		"\033[91m"
# define FG_LGREEN		"\033[92m"
# define FG_LYELLOW		"\033[93m"
# define FG_LBLUE		"\033[94m"
# define FG_LMAGENTA	"\033[95m"
# define FG_LCYAN		"\033[96m"
# define FG_WHITE		"\033[97m"

/////***** background *****/////
# define BG				"\033[48;5;"
# define BG_RED			"\033[41m"
# define BG_GREEN		"\033[42m"
# define BG_YELLOW		"\033[43m"
# define BG_BLUE		"\033[44m"
# define BG_MAGENTA		"\033[45m"
# define BG_CYAN		"\033[46m"
# define BG_LGREY		"\033[47m"
# define BG_DGREY		"\033[100m"
# define BG_LRED		"\033[101m"
# define BG_LGREEN		"\033[102m"
# define BG_LYELLOW		"\033[103m"
# define BG_LBLUE		"\033[104m"
# define BG_LMAGENTA	"\033[105m"
# define BG_LCYAN		"\033[106m"
# define BG_WHITE		"\033[107m"
# define BG_MAKE1		"\033[48;5;236m"
# define BG_MAKE2		"\033[48;5;238m"
# define BG_MAKE3		"\033[48;5;240m"

/////***** option *****/////
# define CL_BOLD		"\033[1m"
# define CL_DIM			"\033[2m"
# define CL_UDLINE		"\033[4m"
# define CL_BLINK		"\033[5m"
# define CL_INVERT		"\033[7m"
# define CL_HIDDEN		"\033[8m"

/////***** NO *****/////
# define NO_COLOR		"\033[0m"

#endif