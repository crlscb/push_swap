/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:32:02 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/17 14:51:26 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	update_minmax(t_stack *s, int n)
{
	if (!s || !n)
		return ;
	if (n < s->min)
		s->min = n;
	if (n > s->max)
		s->max = n;
}

void	parse_numbers(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (strategy_flag(argv[i], a) || bench_flag(argv[i], a))
		{
			i++;
			continue ;
		}
		else if (!is_valid_number(argv[i]))
			error(a, b);
		value = strict_atoi(argv[i]);
		add_node_back(a, value);
		if (i == 1)
		{
			a->min = value;
			a->max = value;
		}
		else
			update_minmax(a, value);
		i++;
	}
}
