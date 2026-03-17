/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:04:31 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/17 12:25:47 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	select_algorithm(t_stack *a, t_stack *b)
{
	a->disorder = compute_disorder(a);
	printf("strategy: %d\n", a->strategy);
	if (a->strategy == 1)
	{
		printf("Algoritmo seleccionado: simple_sort\n");
		simple_sort(a, b);
	}
	else if (a->strategy == 2)
	{
		printf("Algoritmo seleccionado: medium_sort\n");
		medium_sort(a, b);
	}
	else if (a->strategy == 3)
	{
		printf("Algoritmo seleccionado: complex_sort\n");
		//complex_sort(a);
	}
	else if (a->disorder < 0.2)
	{
		printf("Algoritmo seleccionado: simple_sort\n");
		simple_sort(a, b);
	}
	else if (a->disorder < 0.5)
	{
		printf("Algoritmo seleccionado: medium_sort\n");
		medium_sort(a, b);
	}
	else if (a->disorder >= 0.5)
	{
		printf("Algoritmo seleccionado: complex_sort\n");
		//complex_sort(a);
	}
}
