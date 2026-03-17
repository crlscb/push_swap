/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiguel <damiguel@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:38:18 by cescobio          #+#    #+#             */
/*   Updated: 2026/03/16 10:19:20 by damiguel         ###   ########.fr       */
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
	int				min;
	int				max;
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

/*       BENCH       */
void	print_bench(t_stack *a, t_stack *b);

/*      PARSING      */
int		bench_flag(char *str, t_stack *a);
void	error(void);
void	parse_numbers(int argc, char **argv, t_stack *a);
int		strategy_flag(char *str, t_stack *a);

/*       STACK       */
void	add_node_back(t_stack *stack, int value);
double	compute_disorder(t_stack *a);
t_node	*create_node(int value);
t_stack	*init_stack(void);
void	free_stack(t_stack *s);
void	print_stack(t_stack *s);

/*       UTILS       */
int		strict_atoi(char *str);
int		ft_strncmp(const char *s1, const char *s2);
int		estimate_sqrt(int n);

/*     VALIDATION    */
void	check_duplicated(t_stack *a);
int		is_order(t_stack *a);
int		is_valid_number(char *str);

/*    OPERATIONS     */

void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	push(t_stack *from, t_stack *to);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*    SORTING    */
void	select_algorithm(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);

#endif
