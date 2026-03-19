/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:19:31 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 12:18:13 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	fprintf(stderr, "[bench] disorder: %.2f%%\n", (a->disorder * 100));
	fprintf(stderr, "[bench] strategy: %s\n", strategy);
	fprintf(stderr, "[bench] total_ops: %d\n", a->total_ops);
	fprintf(stderr, "[bench] sa: %d :sb %d ss: %d", a->sa + b->sa, a->sb + b->sb, a->ss
		+ b->ss);
	fprintf(stderr, " pa: %d pb: %d\n", a->pa + b->pa, a->pb + b->pb);
	fprintf(stderr, "[bench] ra: %d rb: %d", a->ra + b->ra, a->rb + b->rb);
	fprintf(stderr, " rr: %d rra: %d", a->rr + b->rr, a->rra + b->rra);
	fprintf(stderr, " rrb: %d rrr: %d\n", a->rrb + b->rrb, a->rrr + b->rrr);
}
