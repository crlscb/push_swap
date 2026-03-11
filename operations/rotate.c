/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:00:23 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/10 11:48:49 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//mueve el primer nodo al final del stack
void    rotate(t_stack *stack)
{
    t_node  *first;
    t_node  *last;
    
    //si el stack no existe o tiene menos de 2 nodos no movemos nada
    if (!stack || stack->size < 2)
        return ;
    
    //guardamos el primer nodo
    first = stack->top; 
    
    //el segundo nodo se convierte en el nuevo top
    stack->top = first->next;
    stack->top->prev = NULL;
    
    //bucamos el último nodo de la lista
    last = stack->top;
    while (last->next)
        last = last->next;
    
    //colocamos el antiguo primer nodo al fnal
    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void    ra(t_stack *a)
{
    rotate(a);
    write (1, "ra\n", 3);
}
void    rb(t_stack *b)
{
    rotate(b);
    write (1, "rb\n", 3);
}
void    rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    write (1, "rr\n", 3);
}