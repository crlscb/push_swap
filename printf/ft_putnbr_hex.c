/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:47:50 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 13:49:23 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(uintptr_t n, int to_upper, int fd)
{
	char	*base;
	char	*upper_base;

	base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_hex(n / 16, to_upper, fd);
	if (to_upper)
		write(fd, &upper_base[n % 16], 1);
	else
		write(fd, &base[n % 16], 1);
}
