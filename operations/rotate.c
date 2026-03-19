/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:00:23 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/19 13:52:29 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../printf/ft_printf.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf(1, "ra\n");
	a->total_ops++;
	a->ra++;
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf(1, "rb\n");
	b->total_ops++;
	b->rb++;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf(1, "rr\n");
	a->total_ops++;
	a->rr++;
}
