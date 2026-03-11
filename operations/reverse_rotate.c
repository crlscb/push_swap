/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:00:58 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/10 11:50:25 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//mueve el último nodo del stack al principio
void    reverse_rotate(t_stack *stack)
{
    t_node  *last;

    if (!stack || stack->size < 2)
        return ;

    //empezamos desde el inicio
    last = stack->top;
    
    //buscamos el último nodo
    while (last->next)
        last = last->next;

    //desconectamos el último nodo del final
    last->prev->next = NULL;

    //el último nodo pasa a ser el primero
    last->prev = NULL;
    last->next = stack->top;

    stack->top->prev = last; //el antiguo top ahora apunta hacia atrás al nuevo nodo
    stack->top = last; //actualizamos el top del stack
}

void    rra(t_stack *a)
{
    reverse_rotate(a);
    write (1, "rra\n", 4);
}
void    rrb(t_stack *b)
{
    reverse_rotate(b);
    write (1, "rrb\n", 4);
}
void    rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write (1, "rrr\n", 4);
}