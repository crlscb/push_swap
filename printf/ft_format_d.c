/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:19:49 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 13:47:21 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_d(int n, int fd)
{
	int	digits;
	int	c_count;
	int	num;

	num = n;
	digits = ft_count_digits(num, 10);
	c_count = digits;
	if (num < 0)
		c_count += 1;
	ft_putnbr_fd(num, fd);
	return (c_count);
}
