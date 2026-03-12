/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cescobio <cescobio@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:38:18 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/12 12:07:42 by cescobio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	int				total_ops;
	int				strategy;
	double			disorder;
	int				bench;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				pa;
	int				pb;
	int				rra;
	int				rrb;
	int				rrr;
}					t_stack;

void				ft_parse_numbers(int argc, char **argv, t_stack *a);
long				ft_atoi(const char *str);
int					ft_final_atoi(char *str);
int					ft_is_valid_number(char *str);
int					ft_strategy_flag(char *str, t_stack *a);
int					ft_bench_flag(char *str, t_stack *a);
void				ft_error(void);

void				ft_add_node_back(t_stack *stack, int value);
t_node				*ft_create_node(int value);
void				ft_check_duplicated(t_stack *a);
void				ft_assign_index(t_stack *a);
int					ft_is_order(t_stack *a);
double				ft_compute_disorder(t_stack *a);
void				ft_print_bench(t_stack a, t_stack b);
void				ft_select_algorithm(t_stack *a);

// void ft_select_algorithm(t_stack *a);
/*    OPERATIONS     */
void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				push(t_stack *from, t_stack *to);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				reverse_rotate(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/*    ALGORITHMS    */
// simple_sort.c
void				insertion_sort(t_stack *a, t_stack *b);
int					find_min(t_stack *a);
void				rotate_top(t_stack *a, int index);

#endif
