/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:37:12 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/08 19:08:32 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ans;
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	ans = malloc(sizeof(char) * (s1_len + 1));
	if (ans == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < s1_len)
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
