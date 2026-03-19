/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:27:14 by damiguel          #+#    #+#             */
/*   Updated: 2026/02/05 12:38:56 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(long n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (i + 1);
}
