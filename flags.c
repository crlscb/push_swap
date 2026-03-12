/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:32:41 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/11 16:22:22 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
		{
			i++;
			continue ;
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int	ft_strategy_flag(char *str, t_stack *a)
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
	return (0);
}

int	ft_bench_flag(char *str, t_stack *a)
{
	if (!str || !a)
		return (0);
	if (!ft_strncmp(str, "--bench"))
	{
		a->bench = 1;
		return (1);
	}
	return (0);
}
