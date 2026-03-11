/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:08:15 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/11 15:12:11 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_add_node_back(t_stack *stack, int value)
{
	t_node *new;  // nodo nuevo el cual queremos añadir al stack
	t_node *last; // ultimo nodo del stack
	if (!stack)
		return ;
	new = ft_create_node(value); // creamos el nuevo nodo
	if (!new)
		return ;
	if (!stack->top) // si stack está vacío
		stack->top = new;
	else
	{
		last = stack->top;     // empezamos en el primer nodo
		while (last->next)     // mientras haya un nodo siguiente avanza
			last = last->next; // avanza al siguiente nodo
		last->next = new;      // conectamos el nuevo nodo al final
		new->prev = last;     
			// lo conectamos con el nodo anterior (listas doblemente enlazadas)
	}
	stack->size++; // aumentamos su tamaño
}

// crear nuevo nodo
t_node	*ft_create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// comprobar que no nos pasan numeros iguales (comprobando cada nodo con todos los que vienen después)
void	ft_check_duplicated(t_stack *a)
{
	t_node	*current;
	t_node	*compare;

	current = a->top; // empezamos en el primer nodo
	while (current)   // recorrer lista mientras haya nodos
	{
		compare = current->next; // comparamos con el siguiente
		while (compare)          // mientras haya siguiente
		{
			if (current->value == compare->value)
				ft_error();
			compare = compare->next; // avanzamos al siguiente
		}
		current = current->next;
	}
}

// Marca el nodo con su posición ordenada
void	ft_assign_index(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->value < current->value)
				// incrementamos el valor por cada numero que sea menor que el actual
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

// Comprobar si los números pasados ya están ordenados
int	ft_is_order(t_stack *a)
{
	t_node	*current;

	current = a->top;
	if (!a || !a->top)
		return (1); // vacío o el primer elemento ya está ordenado
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0); // hay desorden
		current = current->next;
	}
	return (1); // todo ordenado
}

// calcula el grado de desorden del stack comprobando todos los pares posibles
double	ft_compute_disorder(t_stack *a)
{
	t_node *i;
	t_node *j;
	int mistakes;
	int total_pairs;

	mistakes = 0;
	total_pairs = 0;

	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++; // contamos todos los pares posibles
			if (i->value > j->value)
				mistakes++; // sumamos si el par está desordenado
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
		// devolvemos porcentaje de pares mal ordenados
}