/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:52:53 by ebroeker          #+#    #+#             */
/*   Updated: 2026/09/11 10:54:02 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sucht die Position des maximalen Rangs in Stack B
*/
static int	get_max_index_pos(t_list *stack, int max_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank == max_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

/*
** Bringt den groessten Rang in B nach oben
*/
static void	bring_max_to_top(t_stack *stack_b, t_op **op_list)
{
	int	max_idx;
	int	pos;

	if (!stack_b || stack_b->size == 0)
		return ;
	max_idx = stack_b->size - 1;
	pos = get_max_index_pos(stack_b->data, max_idx);
	if (pos <= stack_b->size / 2)
	{
		while (stack_b->data->rank != max_idx)
		{
			rotate_rb(stack_b);
			add_op(op_list, "rb");
		}
	}
	else
	{
		while (stack_b->data->rank != max_idx)
		{
			rrb(stack_b);
			add_op(op_list, "rrb");
		}
	}
}

/*
** Hilfsfunktion fuer push_chunks_to_b (Maximal 4 Argumente erlaubt)
*/
static int	check_and_push(t_stack *a, t_stack *b, t_op **op_list, int *i)
{
	int	chunk_size;
	int	sqrt;

	sqrt = 1;
	while (sqrt * sqrt <= a->size + b->size)
		sqrt++;
	chunk_size = (sqrt - 1) * 3;
	if (a->data->rank <= *i)
	{
		pb(a, b);
		add_op(op_list, "pb");
		(*i)++;
		return (1);
	}
	else if (a->data->rank <= *i + chunk_size)
	{
		pb(a, b);
		add_op(op_list, "pb");
		rotate_rb(b);
		add_op(op_list, "rb");
		(*i)++;
		return (1);
	}
	return (0);
}

/*
** Pusht die Elemente in Chunks strukturiert nach B
*/
static void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, t_op **op_list)
{
	int	i;

	i = 0;
	while (stack_a->size > 0)
	{
		if (!check_and_push(stack_a, stack_b, op_list, &i))
		{
			rotate_ra(stack_a);
			add_op(op_list, "ra");
		}
	}
}

/*
** Der Hauptalgorithmus fuer mittlere und grosse Mengen
*/
void	medium_sort(t_stack *stack_a, t_stack *stack_b, t_op **op_list)
{
	rank_stack(stack_a);
	push_chunks_to_b(stack_a, stack_b, op_list);
	while (stack_b->size > 0)
	{
		bring_max_to_top(stack_b, op_list);
		pa(stack_a, stack_b);
		add_op(op_list, "pa");
	}
}
