/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:33:34 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/12 11:57:52 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bench_flag(char *str, t_stack *a)
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
