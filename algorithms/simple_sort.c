/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:48:42 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/11 15:33:55 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// 3 - 10 numeros
// encuentra el num más pequeño y lo intercambia con el primer elemento
void	insertion_sort(t_stack *a, t_stack *b)
{
	int	min;

	while (a->size > 0)
	{
		min = find_min(a); // encontramos el num mas pequeño
		rotate_top(a, min);
		// intercambiamos el min al primer elemento del stack
		pb(a, b); // movemos primer elemento de a a b
	}
	while (b->size > 0)
		pa(a, b);
}
// busccar valor más pequeño y devolver su posición
int	find_min(t_stack *a)
{
	int		min;
	int		min_index;
	int		i;
	t_node	*tmp;

	tmp = tmp->top;
	min = tmp->value;
	min_index = 0;
	i = 0;
	while (tmp)
	{
		// si encontramos un num + pequeño
		if (tmp->value < min)
		{
			min = tmp->value;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}
// void	rotate_top(t_stack *a, int index)
// {
// 	int moves;

//     //si índice está en la primera mitad del stack
//     if (index <= a->size / 2)
//     {
//         //rotamos hacia arriba (ra)
//         while (index--)
//             ra(a);
//     }
//     else
//     {
//         //si estamos más cerca del final (reverse rotate)
//         moves = a->size - index;
//         while (moves--)
//             rra(a);
//     }
// }