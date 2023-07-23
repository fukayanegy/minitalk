/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:21:03 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/16 10:02:16 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_len(char const *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len++;
		}
		while (s[i] != c && s[i + 1] != '\0')
		{
			i++;
		}
		i++;
	}
	return (len);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_matrix_free(char **matrix, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(matrix[i++]);
	free(matrix);
	return (1);
}

static int	ft_split_support(char const *s, char c, char **res, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < len)
	{
		res[i] = (char *)malloc((word_len(&s[j], c) + 1) * (sizeof(char)));
		if (res[i] == NULL)
			return (ft_matrix_free(res, i));
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
			res[i][k++] = s[j++];
		res[i++][k] = '\0';
	}
	res[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**result;

	if (s == NULL)
		return (NULL);
	len = split_len(s, c);
	result = (char **)malloc((len + 1) * (sizeof(char *)));
	if (result == NULL)
		return (NULL);
	if (ft_split_support(s, c, result, len) == 1)
		return (NULL);
	return (result);
}
