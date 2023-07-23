/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:15:08 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/08 13:30:26 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strtrim_start(char const *s1, char const *set, size_t *start)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1))
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	*start = i;
}

static void	ft_strtrim_support(size_t *num, char *ans, char const *s1)
{
	num[0] = 0;
	while (num[1] <= num[2])
		ans[num[0]++] = s1[num[1]++];
	ans[num[0]] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	size_t	num[4];

	if (s1 == NULL)
		return (NULL);
	num[2] = ft_strlen(s1);
	ft_strtrim_start(s1, set, &num[1]);
	while (num[2] > 0)
	{
		if (ft_strchr(set, s1[num[2]]) == NULL)
			break ;
		num[2]--;
	}
	num[3] = num[2] - num[1] + 1;
	if (num[1] > num[2])
		num[3] = 0;
	ans = (char *)malloc((num[3] + 1) * (sizeof(char)));
	if (ans == NULL)
		return (NULL);
	ft_strtrim_support(num, ans, s1);
	return (ans);
}
