/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 20:44:27 by ebroeker          #+#    #+#             */
/*   Updated: 2026/09/10 20:46:22 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rank_stack(t_stack *stack_a)
{
	t_list	*current;
	t_list	*compare;
	int		r;

	current = stack_a->data;
	while (current)
	{
		r = 0;
		compare = stack_a->data;
		while (compare)
		{
			if (compare->content < current->content)
				r++;
			compare = compare->next;
		}
		current->rank = r;
		current = current->next;
	}
}
