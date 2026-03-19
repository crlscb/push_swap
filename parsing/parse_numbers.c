/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:32:02 by damiguel          #+#    #+#             */
/*   Updated: 2026/03/19 17:13:16 by damiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	update_minmax(t_stack *s, int n)
{
	if (!s)
		return ;
	if (n < s->min)
		s->min = n;
	if (n > s->max)
		s->max = n;
}

static void	parse_arr(char **argv, t_stack *a, t_stack *b, int index)
{
	int	i;
	int	value;

	i = 0;
	while (argv[i])
	{
		if (strategy_flag(argv[i], a) || bench_flag(argv[i], a))
		{
			i++;
			continue ;
		}
		else if (!is_valid_number(argv[i]))
			error(a, b);
		value = strict_atoi(argv[i], a, b);
		add_node_back(a, value);
		if (index == 0 && i == 0)
		{
			a->min = value;
			a->max = value;
		}
		else
			update_minmax(a, value);
		i++;
	}
}

void	parse_numbers(char **argv, t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (argv[i])
	{
		arr = ft_split(argv[i], ' ');
		if (!arr)
			error(a, b);
		parse_arr(arr, a, b, i);
		j = 0;
		while (arr[j])
		{
			free(arr[j]);
			j++;
		}
		free(arr);
		if (!check_duplicated(a))
			error(a, b);
		i++;
	}
}
