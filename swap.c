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

static void    swap(stack *s)
{
        t_list  *top;
	t_list	*second;
	int	temp;

	if (!s || !s->data || !s->data->next)
		return; //checking if stack exists and has 2Elements
	top = s->data;
	second = top->next;

	temp = top->content;
	top->content = second->content;
	second->content = temp;

}

void    swap_sa(stack *a)
{
        swap(a);
	write(1, "sa\n", 3);
}

void    swap_sb(stack *b)
{
        swap(b);
        write(1, "sb\n", 3);
}

void    swap_ss(stack *a, stack *b)
{
        swap(a);
	swap(b);
        write(1, "ss\n", 3);
}
