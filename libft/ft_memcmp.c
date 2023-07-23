/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:40:07 by etakaham          #+#    #+#             */
/*   Updated: 2023/05/28 16:18:42 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_sub;
	unsigned char	*s2_sub;

	s1_sub = (unsigned char *)s1;
	s2_sub = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_sub[i] != s2_sub[i])
		{
			return (s1_sub[i] - s2_sub[i]);
		}
		i++;
	}
	return (0);
}
