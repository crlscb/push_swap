/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:58 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/10 11:43:36 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//mover el nodo top del stack 'from' al top del stack 'to'
void    push(t_stack *from, t_stack *to)
{
    t_node  *node; //nodo temporal para guardar el nodo que vamos a mover
    
    //si el stack origen no existe o vacío no movemos nada
    if (!from || from->size == 0)
        return ;
    
    //guardamos el nodo que vamos a mover
    node = from->top;
    
    //quitamos el nodo del stack origen
    from->top = node->next;
    if (from->top) //si todavía queda algún nodo en el stack origen
        from->top->prev = NULL; //el nuevo top no debe tener prev

    //lo colocamos en el top del stack destino
    node->next = to->top;
    if (to->top) //si el stack destino tenía nodos
        to->top->prev = node; //el antiguo top ahora debe apuntar hacia atrás al nodo nuevo
    
    //el nodo movido será el nuevo top del stack destino
    node->prev = NULL;
    to->top = node;

    ///actualizamos tamaños
    from->size--;
    to->size++;
}
void    pa(t_stack *a, t_stack *b)
{
    push(b, a);
    write (1, "pa\n", 3);
}
void    pb(t_stack *a, t_stack *b)
{
    push(a, b);
    write (1, "pb\n", 3);
}