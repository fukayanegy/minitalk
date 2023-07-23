/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:39:22 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:21:06 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_print_s(char *s, ssize_t *len)
{
	if (s == NULL)
	{
		ft_print_s("(null)", len);
		return (0);
	}
	*len += write(1, s, ft_strlen(s));
	if (*len >= INT_MAX)
	{
		*len = -1;
		return (1);
	}
	return (0);
}
