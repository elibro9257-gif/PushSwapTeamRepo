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

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stddef.h> // fuer size_t
#include <stdlib.h> // fuer malloc

typedef struct s_list
{
	int	content;
	int	rank;
	struct s_list	*next;
}		t_list;

typedef struct Stack
{
	t_list	*data;
	int	size;
} 	stack;

typedef struct s_op
{
        char        *cmd;//z.B. "ra","rb", "sa", "rra"
        struct s_op *next;
        struct s_op *prev;
}               t_op;


void	swap_sa(stack *a);
void	swap_sb(stack *b);
void	swap_ss(stack *a, stack *b);
void	rotate_ra(stack *a);
void    rotate_rb(stack *b);
void    rotate_rr(stack *a, stack *b);
void    push(stack *s1, stack *s2);
void    pa(stack *a, stack *b);
void    pb(stack *a, stack *b);
void    rr(stack *s);
void    rra(stack *a);
void    rrb(stack *b);
void    rrr(stack *a, stack *b);

int     add_op(t_op **data, char *cmd);
void    optimize_operations(t_op **data);
void    print_and_free_ops(t_op *data);

//Sortieralgorithmen
void    simple_sort(stack *stack_a, stack *stack_b, t_op **op_list);
void    sort_three(stack *a, t_op **op_list);



#endif
