/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:19:31 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/11 16:17:22 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_print_bench(t_stack a, t_stack b)
{
	printf("[bench] disorder: %.2f%%\n", a.disorder);
	printf("[bench] strategy: %d\n", a.strategy);
	printf("[bench] total_ops: %d\n", a.total_ops);
	printf("[bench] sa: %d :sb %d ss: %d\n", a.sa + b.sa, a.sb + b.sb, a.ss
		+ b.ss);
	printf(" pa: %d pb: %d\n", a.pa + b.pa, a.pb + b.pb);
	printf("[bench] ra: %d :rb %d rr: %d rra: %d rrb: %d rrr: %d\n", a.ra
		+ b.ra, a.rb, a.rr, a.rra, a.rrb, a.rrr);
}
