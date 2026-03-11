/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:01:12 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/10 11:34:46 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

//Construimos stack A a partir de los argumentos del programa
void    ft_parse_numbers(int argc, char **argv, t_stack *a)
{
    int i;
    int value;

    i = 1;
    while (i < argc) //recorremos todos los argumentos excepto el nombre del programa
    {
        if (!ft_is_valid_number(argv[i]))
            ft_error();
        value = ft_final_atoi(argv[i]); //convertimos el argumento a número
        ft_add_node_back(a, value); //añadimos el nodo al stack
        i++;
    }
}

//convertir str a int con overflow
long    ft_atoi(const char *str)
{
    int     i;
    int     sign;
    long    result;

    i = 0;
    sign = 1;
    result = 0;
    
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

//atoi con comprobacionies seguras
int ft_final_atoi(char *str)
{
    long    nb;
    
    if (!ft_is_valid_number(str))
        ft_error();
    
    nb = ft_atoi(str);

    if (nb > 2147483647 || nb < -2147483648)
        ft_error();
    
    return ((int)nb);
    
    
}

//validar formato (comprobar si str tiene formato númerico válido)
int ft_is_valid_number(char *str)
{
    int i;
    
    if (!str || str[0] == '\0')
        return (0);
    
    i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    
    if (!str[i])
        return (0);

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

// Mostrar error y salir del programa (vaga)
void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}


