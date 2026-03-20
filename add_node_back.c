/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:39:16 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/20 11:31:11 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*last;

	if (!stack)
		return ;
	new = create_node(value);
	if (!new)
		return ;
	if (!stack->top)
		stack->top = new;
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	stack->size++;
}
