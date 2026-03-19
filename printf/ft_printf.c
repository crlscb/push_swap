/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:38:42 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 15:03:20 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handleparams(int fd, char const *str, va_list ap)
{
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_handleformat((char)str[i], ap, &char_count, fd);
			if (char_count == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(str[i], fd);
			char_count++;
		}
		i++;
	}
	return (char_count);
}

int	ft_printf(int fd, char const *str, ...)
{
	va_list	ap;
	int		char_count;

	va_start(ap, str);
	char_count = ft_handleparams(fd, str, ap);
	va_end(ap);
	return (char_count);
}
