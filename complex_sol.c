/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:22:29 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 12:22:30 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_list *a)
{
	t_list	*i;
	t_list	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->content < i->content)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
}

static int	get_max_bits(int size)
{
	int	max_rank;
	int	bits;

	max_rank = size - 1;
	bits = 0;
	while (max_rank > 0)
	{
		max_rank >>= 1;
		bits++;
	}
	return (bits);
}

static void	sort_bit(t_stack *a, t_stack *b,
			t_op **op_list, int bit)
{
	if (((a->data->rank >> bit) & 1) == 0)
	{
		pb(a, b);
		add_op(op_list, "pb");
	}
	else
	{
		rotate_ra(a);
		add_op(op_list, "ra");
	}
}

static void	radix_sort(t_stack *a, t_stack *b, t_op **op_list)
{
	int	bit;
	int	i;
	int	count;
	int	max_bits;

	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits)
	{
		count = a->size;
		i = 0;
		while (i++ < count)
			sort_bit(a, b, op_list, bit);
		while (b->size > 0)
		{
			pa(a, b);
			add_op(op_list, "pa");
		}
		bit++;
	}
}

void	complex(t_stack *a, t_stack *b, t_op **op_list)
{
	if (a->size <= 5)
	{
		simple_sort(a, b, op_list);
		return ;
	}
	assign_ranks(a->data);
	radix_sort(a, b, op_list);
}
