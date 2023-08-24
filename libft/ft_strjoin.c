/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:27:57 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/08 13:29:39 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strjoin_support(char const *s1, char const *s2, char *ans)
{
	size_t	i;
	size_t	s_1_len;
	size_t	s_2_len;

	s_1_len = ft_strlen(s1);
	s_2_len = ft_strlen(s2);
	i = 0;
	while (s1[i] != '\0')
	{
		ans[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ans[s_1_len + i] = s2[i];
		i++;
	}
	ans[s_1_len + s_2_len] = '\0';
	return ;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_1_len;
	size_t	s_2_len;
	char	*ans;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s_1_len = ft_strlen(s1);
	s_2_len = ft_strlen(s2);
	ans = malloc((sizeof(char)) * (s_1_len + s_2_len + 1));
	if (ans == NULL)
		return (NULL);
	ft_strjoin_support(s1, s2, ans);
	return (ans);
}
