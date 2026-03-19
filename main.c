/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:25:00 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/19 14:59:11 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sort(t_stack *a, t_stack *b)
{
	select_algorithm(a, b);
	if (a->bench)
		print_bench(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		error(NULL, NULL);
	a = init_stack();
	b = init_stack();
	if (a == NULL || b == NULL)
		error(a, b);
	parse_numbers(argc, argv, a, b);
	if (!check_duplicated(a))
		error (a, b);
	if (!is_order(a))
		do_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
