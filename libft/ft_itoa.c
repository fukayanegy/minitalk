/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:56:46 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/16 10:29:51 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_len(unsigned int n)
{
	int	result;

	result = 0;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static int	size_check(int n, unsigned int *n_sub, bool *is_minus)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
	{
		*n_sub = (long)n * -1;
		size++;
		*is_minus = true;
	}
	else
	{
		*n_sub = n;
		*is_minus = false;
	}
	size += size_len(*n_sub);
	return (size);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	n_sub;
	int				size;
	int				i;
	bool			is_minus;

	size = size_check(n, &n_sub, &is_minus);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 1;
	while (i <= size)
	{
		result[size - i] = '0' + n_sub % 10;
		n_sub /= 10;
		i++;
	}
	if (is_minus)
		result[0] = '-';
	result[size] = '\0';
	return (result);
}
