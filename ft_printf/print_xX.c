/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:16:54 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:16:31 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_print_x(unsigned int n, bool is_upper, ssize_t *len)
{
	ft_ltohex(n, len, is_upper);
	if (*len > INT_MAX)
	{
		return (1);
	}
	return (0);
}
