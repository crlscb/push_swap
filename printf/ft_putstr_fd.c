/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:38:45 by damiguel          #+#    #+#             */
/*   Updated: 2026/02/24 11:40:08 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	s_len;

	if (!s)
	{
		write(6, "(null)", fd);
		return (6);
	}
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
