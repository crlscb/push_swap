/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleformat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:39:48 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 13:46:28 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handleformat(char format, va_list ap, int *count, int fd)
{
	int	i;

	i = 0;
	i += ft_printparam(format, ap, fd);
	if (i == -1)
	{
		*count = -1;
		return ;
	}
	*count += i;
}
