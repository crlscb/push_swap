/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:48:26 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 12:01:38 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_value(t_stack *s, int *distance)
{
	int		max_value;
	t_node	*temp;
	int		i;

	temp = s->top;
	max_value = temp->value;
	i = 0;
	while (temp)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			*distance = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_value);
}

static void	sort_chunks(t_stack *a, t_stack *b)
{
	int	max_value;
	int	distance;

	distance = 0;
	while (b->top)
	{
		max_value = get_max_value(b, &distance);
		if (distance < b->size / 2)
			while (b->top->value != max_value)
				rb(b);
		else
			while (b->top->value != max_value)
				rrb(b);
		pa(a, b);
	}
}

static void	iterate_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	i;
	int	max_elements;
	int	elements_added;

	i = a->size;
	max_elements = max - min;
	elements_added = 0;
	if (!a->top)
		return ;
	while (i >= 0 && elements_added < max_elements && a->top)
	{
		if (a->top->value >= min && a->top->value < max)
		{
			printf("Pushing %d\n", a->top->value);
			pb(a, b);
			elements_added++;
		}
		else
			ra(a);
		i--;
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int		chunks;
	int		range;
	int		i;
	int		min_range;

	chunks = estimate_sqrt(a->size);
	range = (a->max - a->min) / chunks;
	printf("chunk: %d\nrange: %d\n", chunks,range);
	i = 0;
	while (i <= chunks && a->size > 0)
	{
		min_range = a->min + (i * range);
		iterate_chunk(a, b, min_range, min_range + range);
		i++;
	}
	sort_chunks(a, b);
}
