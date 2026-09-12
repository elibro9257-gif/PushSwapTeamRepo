/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:22:44 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 12:22:48 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_list	*current;
	t_list	*compare;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = a->data;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->content > compare->content)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}

void	adaptive(t_stack *a, t_stack *b, double disorder)
{
	t_op	*local_op_list;

	local_op_list = NULL;
	if (disorder < 0.2)
		simple_sort(a, b, &local_op_list);
	else if (disorder < 0.5)
		medium_sort(a, b, &local_op_list);
	else
		complex(a, b);
	if (local_op_list)
	{
		optimize_operations(&local_op_list);
		print_and_free_ops(local_op_list);
	}
}
