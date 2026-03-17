/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:33:08 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/17 12:32:05 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	strategy_flag(char *str, t_stack *a)
{
	if (!str || !a)
		return (0);
	if (!ft_strncmp(str, "--simple"))
	{
		a->strategy = 1;
		return (1);
	}
	if (!ft_strncmp(str, "--medium"))
	{
		a->strategy = 2;
		return (1);
	}
	if (!ft_strncmp(str, "--complex"))
	{
		a->strategy = 3;
		return (1);
	}
	if (!ft_strncmp(str, "--adaptive"))
		return (1);
	return (0);
}
