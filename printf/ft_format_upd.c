/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_upd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:03:19 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 15:08:53 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_upd(double n, int fd)
{
	int	int_value;
	int	decimal;
	int	digits;

	int_value = (int) n;
	decimal = (int)((n - int_value) * 100);
	digits = ft_count_digits(int_value, 10);
	ft_putnbr_fd(int_value, fd);
	write(fd, ".", 1);
	if (decimal < 10)
	{
		write(fd, "0", 1);
		ft_putnbr_fd(decimal, fd);
	}
	else
		ft_putnbr_fd(decimal, fd);
	return (digits + 3);
}
