/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:22:02 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 13:48:36 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_x(int n, int to_upper, int fd)
{
	unsigned int	result;
	int				digits;

	digits = 0;
	result = -1;
	if (n < 0)
		result = result + (n + 1);
	else
		result = n;
	digits += ft_count_digits(result, 16);
	ft_putnbr_hex(result, to_upper, fd);
	return (digits);
}
