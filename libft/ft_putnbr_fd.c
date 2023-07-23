/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:33 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/17 19:57:12 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_single(int n, int fd)
{
	char	last_digit;

	if (n < 10)
	{
		last_digit = '0' + n;
		ft_putchar_fd(last_digit, fd);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_cpy;

	if (n < 0)
	{
		n_cpy = -1 * n;
		ft_putchar_fd('-', fd);
	}
	else
		n_cpy = (unsigned int)n;
	if (n_cpy < 10)
	{
		ft_putnbr_single(n_cpy, fd);
		return ;
	}
	ft_putnbr_fd(n_cpy / 10, fd);
	ft_putnbr_fd(n_cpy % 10, fd);
}
