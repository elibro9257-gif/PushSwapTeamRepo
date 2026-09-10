/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:08:16 by ebroeker          #+#    #+#             */
/*   Updated: 2026/08/16 20:49:24 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stddef.h> // fuer size_t
#include <stdlib.h> // fuer malloc
#include <stdio.h>  // MUSS NOCH RAUSGENOMMEN WERDEN
#include <limits.h> // fuer INT_MAX und INT_MIN FEHLER

typedef enum	e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

// das war was oben hinzugefuegt werden musste
typedef struct s_list
{
	int	content;
	int	rank;
	struct	s_list	*next;
}		t_list;

typedef struct Stack
{
	t_list	*data;
	int		size;
}	stack;

typedef struct s_op
{
	char	*cmd;//z.B. "ra","rb", "sa", "rra"
	struct	s_op *next;
	struct	s_op *prev;
}			t_op;

void	swap_sa(stack *a);
void	swap_sb(stack *b);
void	swap_ss(stack *a, stack *b);
void	rotate_ra(stack *a);
void	rotate_rb(stack *b);
void	rotate_rr(stack *a, stack *b);
void	push(stack *s1, stack *s2);
void	pa(stack *a, stack *b);
void	pb(stack *a, stack *b);
void	rr(stack *s);
void	rra(stack *a);
void	rrb(stack *b);
void	rrr(stack *a, stack *b);

int		add_op(t_op **data, char *cmd);
void	optimize_operations(t_op **data);
void	print_and_free_ops(t_op *data);

int		strategy_parsing(char **argv, t_config *config, int index);
void	init_data(stack *a, stack *b, t_config *config);
int		parse_input(char **argv, stack *a, t_config *config);
int		validate_input(int index, int argc);
int		check_duplicate(int value, stack *a);
void	add_to_stack(int value, stack *a);
int		number_parsing(char **argv, stack *a, int index);
void	complex(stack *a, stack *b);
int		check_integer(char *str, int *pos, int *error_flag);
int		set_error(int *error_flag);
int		get_sign(char *str, int *pos);
void	error();
int		is_option(char *arg);
int		ft_strcmp(const char *s1, const char *s2);
void	adaptive(stack *a, stack *b);

//Sortieralgorithmen
void	simple_sort(stack *stack_a, stack *stack_b, t_op **op_list);
void	sort_three(stack *a, t_op **op_list);
void	medium_sort(stack *stack_a, stack *stack_b, t_op **op_list);
void	rank_stack(stack *stack_a);

#endif
