/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:37:55 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/23 13:39:43 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	action(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static int				count;

	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		count++;
		i = 0;
		if (!c)
			return ;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("server PID: %d\n", getpid());
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
	return (0);
}
