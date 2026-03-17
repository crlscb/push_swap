/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:58 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/12 11:58:52 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (!from || from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	if (from->top)
		from->top->prev = NULL;
	node->next = to->top;
	if (to->top)
		to->top->prev = node;
	node->prev = NULL;
	to->top = node;
	from->size--;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
	a->total_ops++;
	a->pa++;
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
	a->total_ops++;
	a->pb++;
}
