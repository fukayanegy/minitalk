/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:17:17 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:29:15 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ltohex(size_t n, ssize_t *len, bool is_upper)
{
	if (n < 16)
	{
		if (n % 16 < 10)
		{
			ft_print_c('0' + n % 16, len);
		}
		else if (n % 16 >= 10)
		{
			if (is_upper)
			{
				ft_print_c('A' + (n % 16 - 10), len);
			}
			else
			{
				ft_print_c('a' + (n % 16 - 10), len);
			}
		}
		return ;
	}
	ft_ltohex(n / 16, len, is_upper);
	ft_ltohex(n % 16, len, is_upper);
}

int	ft_print_p(void *p, ssize_t *len)
{
	size_t	p_cpy;

	p_cpy = (size_t)p;
	ft_print_s("0x", len);
	ft_ltohex(p_cpy, len, false);
	if (*len > INT_MAX)
	{
		*len = -1;
		return (1);
	}
	return (0);
}
