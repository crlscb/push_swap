/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:44:25 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/20 11:32:13 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	print_stack(t_stack *s)
{
	t_node	*temp;

	temp = s->top;
	while (temp)
	{
		ft_printf(1, "value: %d | index: %d\n", temp->value, temp->index);
		temp = temp->next;
	}
}
