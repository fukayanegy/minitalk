/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:37:09 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/08 12:43:42 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_sub;

	s_sub = (char *)s;
	while (*s_sub)
	{
		if (*s_sub == (char)c)
			return (s_sub);
		s_sub++;
	}
	if (*s_sub == (char)c)
		return (s_sub);
	return (NULL);
}
