/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:25:00 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/11 15:27:43 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    if (argc < 2)
        return (0);
    
    ft_parse_numbers(argc, argv, &a);
    ft_check_duplicated(&a);

    if (ft_is_order(&a))
        return (0);

    ft_assign_index(&a);

    insertion_sort(&a, &b);

    return (0);
}

/*int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    t_node  *tmp;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    if (argc < 2)
        return (0);
    
    ft_parse_numbers(argc, argv, &a);
    ft_check_duplicated(&a);
    
    if (ft_is_order(&a))
    {
        printf("Stack ya está ordenado\n");
        return (0);
    }
    
    ft_assign_index(&a);
    ft_assign_index(&b);
    //ft_select_algorithm(&a);

    //sa(&a);
    //pb(&a, &b);
    //ra(&a);
    rra(&a);
    printf("Stack a\n");
    tmp = a.top;
    while (tmp)
    {
        printf("value: %d | index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }
    printf("Stack b\n");
    tmp = b.top;
    while (tmp)
    {
        printf("value: %d | index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }
    printf("disorder: %f\n", ft_compute_disorder(&a));

    return (0);
}*/

