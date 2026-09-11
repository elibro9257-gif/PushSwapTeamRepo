/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:22:22 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 12:22:23 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *s1, t_stack *s2)
{
	t_list	*temp;

	if (!s2->data)
		return ;
	temp = s2->data;
	s2->data = s2->data->next;
	temp->next = s1->data;
	s1->data = temp;
	s2->size--;
	s1->size++;
}

void	pa(t_stack *a, t_stack *b, t_config *config)
{
	push(a, b);
	if (config->bench)
		a->bench->pa++;
	else
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, t_config *config)
{
	push(b, a);
	if (config->bench)
		b->bench->pb++;
	else
		write(1, "pb\n", 3);
}
