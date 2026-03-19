/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:38:50 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 14:03:03 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(int fd, char const *str, ...);
int		ft_format_c(char c, int fd);
int		ft_format_s(char *str, int fd);
int		ft_format_p(int *p, int fd);
int		ft_format_d(int n, int fd);
int		ft_format_upd(double n, int fd);
int		ft_format_u(unsigned int n, int fd);
int		ft_format_x(int n, int to_upper, int fd);
int		ft_format_escape(int fd);
void	ft_putnbr_hex(uintptr_t n, int to_upper, int fd);
int		ft_printparam(char format, va_list ap, int fd);
void	ft_handleformat(char format, va_list ap, int *count, int fd);
int		ft_count_digits(long n, int base);
int		ft_putchar_fd(char c, int fd);
int		ft_strlen(char *s);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);

#endif
