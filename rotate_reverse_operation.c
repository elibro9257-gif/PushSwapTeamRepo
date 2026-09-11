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

void	rra(t_stack *a, t_config *config)
{
	rr(a);
	if (config->bench)
		a->bench->rra++;
	else
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_config *config)
{
	rr(b);
	if (config->bench)
		b->bench->rrb++;
	else
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, t_config *config)
{
	rr(a);
	rr(b);
	if (config->bench)
		a->bench->rrr++;
	else
		write(1, "rrr\n", 4);
}
