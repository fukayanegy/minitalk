/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:37:31 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/16 10:12:52 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	s1_u;
	unsigned char	s2_u;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (((int)s1[i] != 0 || (int)s2[i] != 0) && i < n)
	{
		if ((int)s1[i] != (int)s2[i])
		{
			s1_u = (unsigned char)s1[i];
			s2_u = (unsigned char)s2[i];
			return ((int)s1_u - (int)s2_u);
		}
		i++;
	}
	return (0);
}
