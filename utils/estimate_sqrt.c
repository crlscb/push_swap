/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate_sqrt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:20:22 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/13 14:03:30 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Esta función calcula una estimación de la raíz cuadrada del número.
//Es bastante pesada si se le pasa un número largo.
int	estimate_sqrt(int n)
{
	int		i;
	long	low_diff;
	long	high_diff;

	if (n < 1)
		return (0);
	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	low_diff = i * i;
	high_diff = (i + 1) * (i + 1);
	if ((n - low_diff) <= (high_diff - n))
		return (i);
	return (i + 1);
}
