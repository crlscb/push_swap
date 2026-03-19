/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:00:58 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/19 13:52:32 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../printf/ft_printf.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf(1, "rra\n");
	a->total_ops++;
	a->rra++;
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf(1, "rrb\n");
	b->total_ops++;
	b->rrb++;
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	a->total_ops++;
	a->rrr++;
}
