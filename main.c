/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:25:00 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/11 15:46:19 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	init_stack(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
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
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_node	*tmp;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		return (0);
	ft_parse_numbers(argc, argv, &a);
	ft_check_duplicated(&a);
	if (ft_is_order(&a))
	{
		printf("Stack ya está ordenado\n");
		return (0);
	}
	ft_select_algorithm(&a);
	printf("Stack a\n");
	tmp = a.top;
	while (tmp)
	{
		printf("value: %d | index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("Stack b\n");
	tmp = b.top;
	while (tmp)
	{
		printf("value: %d | index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	if (a.bench)
		ft_print_bench(a, b);
	return (0);
}
