/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:48:29 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/17 15:25:43 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_digits(int min, int max)
{
	int	digits;

	if (!min && !max)
		return (0);
	digits = 1;
	while (max >= 10 || min <= -10)
	{
		digits++;
		max = max / 10;
		min = min / 10;
		printf("max: %d\nmin: %d\n", max, min);
	}
	return (digits);
}

static void	set_index(t_stack *a)
{
	t_node *tmp;

	tmp = a->top;
	while (tmp)
	{
		tmp->index = tmp->value % 10;
		tmp = tmp->next;
	}
}

void	complex_sort(t_stack *a, t_stack *b)
{
	int	max_digits;

	max_digits = get_max_digits(a->min, a->max);
	set_index(a);
	(void) b;
}
