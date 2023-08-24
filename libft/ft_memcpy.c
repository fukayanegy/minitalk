/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:40:07 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/08 19:06:45 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_sub;
	char		*src_sub;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	dest_sub = (char *)dest;
	src_sub = (char *)src;
	i = 0;
	while (i < n)
	{
		dest_sub[i] = src_sub[i];
		i++;
	}
	return (dest);
}
