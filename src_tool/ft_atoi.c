/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:20:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/24 15:14:30 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_overflow(long sign);

long long	ft_atoi(const char *str)
{
	long long	num;
	long long	sign;

	num = 0;
	sign = 0;
	while ((0x09 <= *str && *str <= 0x0d) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (0x30 <= *str && *str <= 0x39)
	{
		if (num > num * 10 + (*str - 0x30) + sign)
			return (ft_atoi_overflow(sign));
		num = num * 10 + (*str - 0x30);
		str++;
	}
	if (sign)
		return (num * sign);
	return (num);
}

int	ft_atoi_overflow(long sign)
{
	if (sign == 0)
		return (-1);
	return (0);
}
