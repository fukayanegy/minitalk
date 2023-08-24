/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:42:19 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:26:34 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(int n, ssize_t *len)
{
	unsigned int	n_cpy;

	if (n < 0)
	{
		n_cpy = n * -1;
		ft_print_c('-', len);
	}
	else
	{
		n_cpy = n;
	}
	ft_print_u(n_cpy, len);
	if (*len >= INT_MAX)
	{
		*len = -1;
		return (1);
	}
	return (0);
}
