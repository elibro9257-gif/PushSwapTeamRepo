/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 11:02:44 by ebroeker          #+#    #+#             */
/*   Updated: 2026/09/11 11:10:51 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(stack *a, t_op **op_list, t_config *config)
{
	int	f;
	int	s;
	int	t;

	if (a->size != 3)
		return ;
	f = a->data->content;
	s = a->data->next->content;
	t = a->data->next->next->content;
	if (f > s && s < t && f < t)
		(swap_sa(a, config), add_op(op_list, "sa"));
	else if (f > s && s > t && f > t)
		(swap_sa(a, config), add_op(op_list, "sa"), rra(a, config), add_op(op_list, "rra"));
	else if (f > s && s < t && f > t)
		(rotate_ra(a, config), add_op(op_list, "ra"));
	else if (f < s && s > t && f < t)
		(swap_sa(a, config), add_op(op_list, "sa"),
			rotate_ra(a, config), add_op(op_list, "ra"));
	else if (f < s && s > t && f > t)
		(rra(a, config), add_op(op_list, "rra"));
}
