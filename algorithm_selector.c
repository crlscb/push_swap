/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:04:31 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/12 13:51:37 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	simple_sort(t_stack *a)
{
	t_stack b;

	b.top = NULL;
	b.size = 0;

	insertion_sort(a, &b);
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
	{
		printf("Algoritmo seleccionado: simple_sort\n");
		simple_sort(a);
	}
	else if (a->strategy == 2)
	{
		printf("Algoritmo seleccionado: medium_sort\n");
		medium_sort(a);
	}
	else if (a->strategy == 3)
	{
		printf("Algoritmo seleccionado: complex_sort\n");
		complex_sort(a);
	}
	else if (a->disorder < 0.2)
	{
		printf("Algoritmo seleccionado: simple_sort\n");
		simple_sort(a);
	}
		
	else if (a->disorder < 0.5)
	{
		printf("Algoritmo seleccionado: medium_sort\n");
		medium_sort(a);
	}
	else if (a->disorder >= 0.5)
	{
		printf("Algoritmo seleccionado: complex_sort\n");
		complex_sort(a);
	}
}
