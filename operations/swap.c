/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:11 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/07 13:23:16 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//intercambia los dos primeros nodos del stack
void  swap(t_stack *stack)
{
    t_node  *first;
    t_node  *second;

     //si no existe o tiene menos de 2 nodos no movemos nada
    if (!stack || stack->size < 2)
        return ;
    
    //guardamos los dos primeros nodos
    first = stack->top;
    second = first->next;

    //quitamos temporalmente second de la lista
    first->next = second->next;

    //si hay un nodo después de second, corregimos su prev
    if(second->next)
        second->next->prev = first;
    
    //colocamos second delante de first
    second->next = first;
    first->prev = second;
    second->prev = NULL;

    //actualizamos el top del stack
    stack->top = second;
}

void sa(t_stack *a)
{
    swap(a);
    write (1, "sa\n", 3);
}

void sb(t_stack *b)
{
    swap(b);
    write (1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    write (1, "ss\n", 3);
}