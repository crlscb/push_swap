/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:04:31 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/11 15:28:08 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	simple_sort(t_stack *a)
{
	return (0);
}

int	medium_sort(t_stack *a)
{
	return (0);
}

int	complex_sort(t_stack *a)
{
	return (0);
}

void	ft_select_algorithm(t_stack *a)
{
	double	disorder;

	a->disorder = ft_compute_disorder(a);
	if (a->strategy == 1)
		simple_sort(a);
	else if (a->strategy == 2)
		medium_sort(a);
	else if (a->strategy == 3)
		complex_sort(a);
	else if (a->disorder < 0.2)
		simple_sort(a);
	else if (a->disorder < 0.5)
		medium_sort(a);
	else if (a->disorder >= 0.5)
		complex_sort(a);
}
