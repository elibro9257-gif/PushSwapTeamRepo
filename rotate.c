/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 18:44:37 by ebroeker          #+#    #+#             */
/*   Updated: 2026/08/16 20:33:06 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_list	*top;
	t_list	*last;

	if (!s || !s->data || !s->data->next)
		return ;
	top = s->data;
	last = s->data;
	while (last->next != NULL)
		last = last->next;
	s->data = top->next;
	last->next = top;
	top->next = NULL;
}

void	rotate_ra(t_stack *a)
{
	rotate(a);
	a->bench->ra++;
}

void	rotate_rb(t_stack *b)
{
	rotate(b);
	b->bench->rb++;
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	a->bench->rr++;
}
