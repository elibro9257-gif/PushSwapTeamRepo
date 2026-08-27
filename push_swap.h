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



#endif
