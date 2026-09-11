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

void	swap_sa(t_stack *a, t_config *config)
{
	swap(a);
	if (config->bench)
		a->bench->sa++;
	else
		write(1, "sa\n", 3);
}

void	swap_sb(t_stack *b, t_config *config)
{
	swap(b);
	if (config->bench)
		b->bench->sb++;
	else
		write(1, "sb\n", 3);
}

void	swap_ss(t_stack *a, t_stack *b, t_config *config)
{
	swap(a);
	swap(b);
	if (config->bench)
		a->bench->ss++;
	else
		write(1, "ss\n", 3);
}
