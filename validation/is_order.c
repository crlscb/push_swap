/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:36:42 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/12 12:03:46 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_order(t_stack *a)
{
	t_node	*current;

	current = a->top;
	if (!a || !a->top)
		return (1);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
