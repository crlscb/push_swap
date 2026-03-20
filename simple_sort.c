/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:48:42 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/20 11:31:28 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b)
{
	int	min;

	while (a->size > 0)
	{
		min = find_min(a);
		rotate_top(a, min);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}

int	find_min(t_stack *a)
{
	int		min;
	int		min_index;
	int		i;
	t_node	*tmp;

	tmp = a->top;
	min = tmp->value;
	min_index = 0;
	i = 0;
	while (tmp)
	{
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

void	rotate_top(t_stack *a, int index)
{
	int	moves;

	if (index <= a->size / 2)
	{
		while (index--)
			ra(a);
	}
	else
	{
		moves = a->size - index;
		while (moves--)
			rra(a);
	}
}
