/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:38:46 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/23 20:24:02 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

int		ft_printf(const char *format, ...);
int		ft_print_c(unsigned char c, ssize_t *len);
int		ft_print_s(char *s, ssize_t *len);
int		ft_print_p(void *p, ssize_t *len);
int		ft_print_di(int n, ssize_t *len);
int		ft_print_u(unsigned int n, ssize_t *len);
int		ft_print_x(unsigned int n, bool is_upper, ssize_t *len);
void	ft_ltohex(size_t n, ssize_t *len, bool is_upper);

#endif
