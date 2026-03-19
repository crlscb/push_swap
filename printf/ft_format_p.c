/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:19:49 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 13:48:05 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_ptrdigits(unsigned long n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		i++;
		n = n / 16;
	}
	return (i + 1);
}

int	ft_format_p(int *p, int fd)
{
	uintptr_t	ptr;
	int			counter;

	if (!p)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	counter = 2;
	ptr = (uintptr_t)p;
	counter += ft_ptrdigits(ptr);
	ft_putnbr_hex(ptr, 0, fd);
	return (counter);
}
