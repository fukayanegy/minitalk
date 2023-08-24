/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:48:49 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/16 18:36:11 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char str_i, bool minus_sign, long ans)
{
	if (ans == LONG_MAX / 10 && minus_sign == false)
	{
		if ('8' <= str_i && str_i <= '9')
		{
			return (1);
		}
	}
	else if (ans > LONG_MAX / 10 && minus_sign == false)
		return (1);
	else if (ans == LONG_MAX / 10 && minus_sign == true && ('9' <= str_i))
		return (2);
	else if (ans > LONG_MAX / 10 && minus_sign == true)
		return (2);
	return (0);
}

static long	ft_strtol(const char *str, bool minus_sign)
{
	long	ans;
	int		i;

	i = 0;
	ans = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (ft_check(str[i], minus_sign, ans) == 1)
			return (LONG_MAX);
		else if (ft_check(str[i], minus_sign, ans) == 2)
			return (LONG_MIN);
		ans *= 10;
		ans += str[i] - 48;
		i++;
	}
	if (minus_sign)
		ans *= -1;
	return (ans);
}

int	ft_atoi(const char *str)
{
	int		num;
	bool	minus_sign;

	minus_sign = false;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_sign = true;
		str++;
	}
	num = (int)ft_strtol(str, minus_sign);
	return (num);
}
