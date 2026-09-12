/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 18:44:11 by ebroeker          #+#    #+#             */
/*   Updated: 2026/08/16 20:28:59 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	t_list	*top;
	t_list	*second;
	int		temp;

	if (!s || !s->data || !s->data->next)
		return ;
	top = s->data;
	second = top->next;
	temp = top->content;
	top->content = second->content;
	second->content = temp;
}

void	swap_sa(t_stack *a)
{
	swap(a);
	a->bench->sa++;
}

void	swap_sb(t_stack *b)
{
	swap(b);
	b->bench->sb++;
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	a->bench->ss++;
}
