/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printparam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:38:49 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 14:13:49 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printparam(char format, va_list ap, int fd)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = ft_format_c(va_arg(ap, int), fd);
	else if (format == 's')
		i = ft_format_s((char *)va_arg(ap, int *), fd);
	else if (format == 'p')
		i = ft_format_p(va_arg(ap, int *), fd);
	else if (format == 'd' || format == 'i')
		i = ft_format_d(va_arg(ap, int), fd);
	else if (format == 'u')
		i = ft_format_u(va_arg(ap, int), fd);
	else if (format == 'x')
		i = ft_format_x(va_arg(ap, int), 0, fd);
	else if (format == 'X')
		i = ft_format_x(va_arg(ap, int), 1, fd);
	else if (format == '%')
		i = ft_format_escape(fd);
	else if (format == 'D')
		i = ft_format_upd(va_arg(ap, double), fd);
	else
		return (-1);
	return (i);
}
