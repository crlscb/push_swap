/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:46:52 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/16 10:04:03 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *s)
{
	t_node	*temp;
	t_node	*next;

	if (!s)
		return ;
	temp = s->top;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(s);
}
