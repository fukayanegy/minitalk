/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:40:07 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/16 09:48:21 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_hed(char *dest_sub, char *src_sub, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest_sub[i] = src_sub[i];
		i++;
	}
}

static void	ft_memmove_tail(char *dest_sub, char *src_sub, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest_sub[n - i - 1] = src_sub[n - i - 1];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_sub;
	char	*src_sub;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	dest_sub = (char *)dest;
	src_sub = (char *)src;
	if (dest < src)
		ft_memmove_hed(dest_sub, src_sub, n);
	else
		ft_memmove_tail(dest_sub, src_sub, n);
	dest = (void *)dest_sub;
	return (dest);
}
