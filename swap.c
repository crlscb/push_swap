/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:11 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/20 11:32:13 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	stack->top = second;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf(1, "sa\n");
	a->total_ops++;
	a->sa++;
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf(1, "sb\n");
	b->total_ops++;
	b->sb++;
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf(1, "ss\n");
	a->total_ops++;
	a->ss++;
}
