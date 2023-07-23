/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:38:40 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:19:44 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(unsigned char c, ssize_t *len)
{
	*len += write(1, &c, 1);
	if (*len >= INT_MAX)
	{
		*len = -1;
		return (1);
	}
	return (0);
}
