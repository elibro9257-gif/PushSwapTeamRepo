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

void	rotate_ra(stack *a, t_config *config)
{
	rotate(a);
	if (config->bench)
		a->bench->ra++;
	else
		write(1, "ra\n", 3);
}

void	rotate_rb(stack *b, t_config *config)
{
	rotate(b);
	if (config->bench)
		b->bench->rb++;
	else
		write(1, "rb\n", 3);
}

void	rotate_rr(stack *a, stack *b, t_config *config)
{
	rotate(a);
	rotate(b);
	if (config->bench)
		a->bench->rr++;
	else
		write(1, "rr\n", 3);
}
