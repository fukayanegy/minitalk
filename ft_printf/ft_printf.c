/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:04:54 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:44:46 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_args(char extension, ssize_t *len, va_list ap)
{
	if (extension == 'c')
		ft_print_c(va_arg(ap, int), len);
	else if (extension == 's')
		ft_print_s(va_arg(ap, char *), len);
	else if (extension == 'p')
		ft_print_p(va_arg(ap, void *), len);
	else if (extension == 'd' || extension == 'i')
		ft_print_di(va_arg(ap, int), len);
	else if (extension == 'u')
		ft_print_u(va_arg(ap, unsigned int), len);
	else if (extension == 'x')
		ft_print_x(va_arg(ap, unsigned int), false, len);
	else if (extension == 'X')
		ft_print_x(va_arg(ap, unsigned int), true, len);
	else if (extension == '%')
		ft_print_c('%', len);
	if (*len == -1)
		return (1);
	else
		return (0);
}

static bool	ft_check_extention(char next)
{
	const char	*extension_alphabet = "cspdiuxX%";
	size_t		i;

	i = 0;
	while (extension_alphabet[i] != '\0')
	{
		if (extension_alphabet[i] == next)
			return (true);
		i++;
	}
	return (false);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	ssize_t	len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (ft_check_extention(format[++i]))
				ft_print_args(format[i], &len, ap);
			else
				continue ;
			i++;
		}
		else
			ft_print_c(format[i++], &len);
		if (len >= INT_MAX || len == -1)
		{
			len = -1;
			break ;
		}
	}
	va_end(ap);
	return ((int)len);
}
