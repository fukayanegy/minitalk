/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:44:56 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:28:02 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int n, ssize_t *len)
{
	char	n_cpy;

	if (n < 10)
	{
		n_cpy = '0' + n;
		ft_print_c(n_cpy, len);
		if (*len >= INT_MAX)
		{
			*len = -1;
			return (1);
		}
		return (0);
	}
	else
	{
		ft_print_u(n / 10, len);
		ft_print_u(n % 10, len);
		return (1);
	}
}
