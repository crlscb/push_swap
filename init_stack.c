/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:37:54 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/20 11:31:28 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	s->min = 0;
	s->max = 0;
	s->total_ops = 0;
	s->strategy = 0;
	s->bench = 0;
	s->sa = 0;
	s->sb = 0;
	s->ss = 0;
	s->ra = 0;
	s->rb = 0;
	s->rr = 0;
	s->pa = 0;
	s->pb = 0;
	s->rra = 0;
	s->rrb = 0;
	s->rrr = 0;
	return (s);
}
