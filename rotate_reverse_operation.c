/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:22:13 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 12:22:14 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *s)
{
	t_list	*temp;
	t_list	*prev;

	temp = s->data;
	if (!s->data || s->size < 2)
		return ;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	temp->next = s->data;
	prev->next = NULL;
	s->data = temp;
}

void	rra(t_stack *a)
{
	rr(a);
	a->bench->rra++;
}

void	rrb(t_stack *b)
{
	rr(b);
	b->bench->rrb++;
}

void	rrr(t_stack *a, t_stack *b)
{
	rr(a);
	rr(b);
	a->bench->rrr++;
}
