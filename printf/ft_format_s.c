/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:19:24 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 13:48:21 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char *str, int fd)
{
	int		str_len;

	str_len = 0;
	str_len += ft_strlen(str);
	if (!str)
	{
		str_len += 6;
		str = "(null)";
	}
	ft_putstr_fd(str, fd);
	return (str_len);
}

int	ft_format_s(char *str, int fd)
{
	int	res_len;

	res_len = 0;
	res_len = ft_print_format(str, fd);
	return (res_len);
}
