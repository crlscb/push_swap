/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:58 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/19 13:52:34 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../printf/ft_printf.h"

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
	ft_printf(1, "pa\n");
	a->total_ops++;
	a->pa++;
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf(1, "pb\n");
	a->total_ops++;
	a->pb++;
}
