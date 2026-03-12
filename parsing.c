/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:01:12 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/11 16:22:04 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_parse_numbers(int argc, char **argv, t_stack *a)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (ft_strategy_flag(argv[i], a) || ft_bench_flag(argv[i], a))
		{
			i++;
			continue ;
		}
		else if (!ft_is_valid_number(argv[i]))
			ft_error();
		value = ft_final_atoi(argv[i]);
		ft_add_node_back(a, value);
		i++;
	}
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_final_atoi(char *str)
{
	long	nb;

	if (!ft_is_valid_number(str))
		ft_error();
	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
		ft_error();
	return ((int)nb);
}

int	ft_is_valid_number(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
