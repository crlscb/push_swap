/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:04:31 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/20 11:31:28 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algorithm(t_stack *a, t_stack *b)
{
	a->disorder = compute_disorder(a);
	if (a->strategy == 1)
		simple_sort(a, b);
	else if (a->strategy == 2)
		medium_sort(a, b);
	else if (a->strategy == 3)
		complex_sort(a, b);
	else if (a->disorder < 0.2)
		simple_sort(a, b);
	else if (a->disorder < 0.5)
		medium_sort(a, b);
	else if (a->disorder >= 0.5)
		complex_sort(a, b);
}
