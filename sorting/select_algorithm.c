/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:04:31 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/13 12:53:46 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	select_algorithm(t_stack *a, t_stack *b)
{
	a->disorder = compute_disorder(a);
	printf("strategy: %d\n", a->strategy);
	if (a->strategy == 0)
		return ;
	if (a->strategy == 1)
		return ;
	if (a->strategy == 2)
		medium_sort(a, b);
	if (a->strategy == 3)
		return ;
	return ;
}
