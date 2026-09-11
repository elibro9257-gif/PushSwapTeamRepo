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

# include <unistd.h>
# include <stddef.h> // fuer size_t
# include <stdlib.h> // fuer malloc
# include <stdio.h>  // MUSS NOCH RAUSGENOMMEN WERDEN
# include <limits.h> // fuer INT_MAX und INT_MIN FEHLER

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_bench
{
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
}	t_bench;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

// das war was oben hinzugefuegt werden musste
typedef struct s_list
{
	int				content;
	int				rank;
	struct s_list	*next;
}		t_list;

typedef struct Stack
{
	t_list	*data;
	int		size;
	t_bench	*bench;
}	t_stack;

typedef struct s_op
{
	char		*cmd;
	struct s_op	*next;
	struct s_op	*prev;
}			t_op;

void	swap_sa(t_stack *a);
void	swap_sb(t_stack *b);
void	swap_ss(t_stack *a, t_stack *b);
void	rotate_ra(t_stack *a);
void	rotate_rb(t_stack *b);
void	rotate_rr(t_stack *a, t_stack *b);
void	push(t_stack *s1, t_stack *s2);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rr(t_stack *s);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int		add_op(t_op **data, char *cmd);
void	optimize_operations(t_op **data);
void	print_and_free_ops(t_op *data);
int		check_cancel_and_combine(t_op **head, t_op **curr, t_op *next);
int		strategy_parsing(char **argv, t_config *config, int index);
void	init_data(t_stack *a, t_stack *b, t_config *config);
int		parse_input(char **argv, t_stack *a, t_config *config);
int		validate_input(int index, int argc);
int		check_duplicate(int value, t_stack *a);
void	add_to_stack(int value, t_stack *a);
int		number_parsing(char **argv, t_stack *a, int index);
void	complex(t_stack *a, t_stack *b);
int		check_integer(char *str, int *pos, int *error_flag);
int		set_error(int *error_flag);
int		get_sign(char *str, int *pos);
void	error(void);
int		is_option(char *arg);
int		ft_strcmp(const char *s1, const char *s2);
void	adaptive(t_stack *a, t_stack *b, double disorder);
void	init_bench(t_bench *bench);
long	total_operations(t_bench *bench);
void	print_benchmark(t_bench *bench, t_config *config,
			double disorder);
double	compute_disorder(t_stack *a);
//Sortieralgorithmen
void	simple_sort(t_stack *stack_a, t_stack *stack_b,
			t_op **op_list);
void	sort_three(t_stack *a, t_op **op_list);
void	medium_sort(t_stack *stack_a, t_stack *stack_b,
			t_op **op_list);
void	rank_stack(t_stack *stack_a);
int		parse_validate(char **argv, int argc,
			t_stack *a, t_config *config);
void	init_program(t_stack *a, t_stack *b, t_config *config, t_bench *bench);
void	run_stratergy(t_stack *a, t_stack *b,
			t_config *config, double disorder);
int		check_cancel_and_combine(t_op **head, t_op **curr, t_op *next);
#endif
