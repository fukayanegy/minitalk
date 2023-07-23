/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:37:36 by etakaham          #+#    #+#             */
/*   Updated: 2023/05/28 15:44:23 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_sub;
	bool	ans;

	s_sub = (char *)s;
	ans = false;
	while (*s_sub)
	{
		if (*s_sub == (char)c)
			ans = true;
		s_sub++;
	}
	if ((char)c == '\0')
		return (s_sub);
	if (!ans)
		return (NULL);
	while (*s_sub != (char)c)
		s_sub--;
	return (s_sub);
}
