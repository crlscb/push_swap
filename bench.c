/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:19:31 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 17:13:34 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

static char	*strategy_str(t_stack *a)
{
	if (a->strategy == 0)
		return ("Adaptive | O(n√n)");
	if (a->strategy == 1)
		return ("Simple | O(n²)");
	if (a->strategy == 2)
		return ("Medium | O(n√n)");
	if (a->strategy == 3)
		return ("Complex | O(n log n)");
	return (NULL);
}

void	print_bench(t_stack *a, t_stack *b)
{
	char	*strategy;

	strategy = strategy_str(a);
	ft_printf(2, "[bench] disorder: %D%%\n", (a->disorder * 100));
	ft_printf(2, "[bench] strategy: %s\n", strategy);
	ft_printf(2, "[bench] total_ops: %d\n", a->total_ops);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d", a->sa + b->sa, a->sb
		+ b->sb, a->ss + b->ss);
	ft_printf(2, " pa: %d pb: %d\n", a->pa + b->pa, a->pb + b->pb);
	ft_printf(2, "[bench] ra: %d rb: %d", a->ra + b->ra, a->rb + b->rb);
	ft_printf(2, " rr: %d rra: %d", a->rr + b->rr, a->rra + b->rra);
	ft_printf(2, " rrb: %d rrr: %d\n", a->rrb + b->rrb, a->rrr + b->rrr);
}
