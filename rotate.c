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

static void	rotate(stack *s)
{
	t_list	*top;
	t_list	*last;

	if (!s || !s->data || !s->data->next) //data ist wie head
		return ;
	top = s->data;
	last = s->data;

	while (last->next != NULL)
		last = last->next;

	s->data = top->next;

	last->next = top;
	top->next = NULL;
}

void	rotate_ra(stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void    rotate_rb(stack *b)
{
        rotate(b);
        write(1, "rb\n", 3);
}

void    rotate_rr(stack *a, stack *b)
{
        rotate(a);
	rotate(b);
        write(1, "rr\n", 3);
}
