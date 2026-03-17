/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:25:00 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/16 10:19:59 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (a == NULL || b == NULL)
		error();
	parse_numbers(argc, argv, a);
	check_duplicated(a);
	if (is_order(a))
	{
		printf("Stack ya está ordenado\n");
		return (0);
	}
	select_algorithm(a, b);
	printf("Stack a\n");
	print_stack(a);
	printf("Stack b\n");
	print_stack(b);
	if (a->bench)
		print_bench(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
