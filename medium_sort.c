/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:05:47 by ebroeker          #+#    #+#             */
/*   Updated: 2026/09/10 10:06:46 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_stack(stack *stack_a)
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
		current->rank = r; // Setzt den passenden Rang für den Chunk-Sort
		current = current->next;
	}
}

// Hilfsfunktion zur Berechnung der Quadratwurzel (für die Chunk-Größe)
static int	ft_int_sqrt(int number)
{
	int	i;

	if (number < 0)
		return (0);
	i = 1;
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}

// Sucht die Position des maximalen INDEX in Stack B
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

// Bringt den größten Index in B nach oben, um ihn fehlerfrei auf A zu pushen
static void	bring_max_to_top(stack *stack_b, t_op **op_list)
{
	int	max_idx;
	int	pos;

	if (!stack_b || stack_b->size == 0)
		return ;
	// Da wir indiziert haben, ist die größte Zahl einfach (Größe von B - 1)
	max_idx = stack_b->size - 1;
	pos = get_max_index_pos(stack_b->data, max_idx);
	if (pos <= stack_b->size / 2)
	{
		// KORRIGIERT: rank statt index
		while (stack_b->data->rank != max_idx)
		{
			rotate_rb(stack_b);
			add_op(op_list, "rb");
		}
	}
	else
	{
		// KORRIGIERT: rank statt index
		while (stack_b->data->rank != max_idx)
		{
			rrb(stack_b); // Deine rrb-Funktion aus der Operation-Datei
			add_op(op_list, "rrb");
		}
	}
}

static void	push_chunks_to_b(stack *stack_a, stack *stack_b, t_op **op_list)
{
	int	chunk_size;
	int	i;

	// Multiplikator 3 bei 100 Zahlen, für 500 Zahlen optimiert man meist auf ~4-5
	chunk_size = ft_int_sqrt(stack_a->size) * 3;
	i = 0;
	while (stack_a->size > 0)
	{
		// Wenn der Index der obersten Zahl im aktuellen Fenster liegt
		if (stack_a->data->rank <= i)
		{
			pb(stack_a, stack_b);
			add_op(op_list, "pb");
			i++;
		}
		// "Sandglass" Optimierung: Wenn sie im erweiterten Fenster liegt, pushen und rotieren
		else if (stack_a->data->rank <= i + chunk_size)
		{
			pb(stack_a, stack_b);
			add_op(op_list, "pb");
			rotate_rb(stack_b);
			add_op(op_list, "rb");
			i++;
		}
		else
		{
			rotate_ra(stack_a);
			add_op(op_list, "ra");
		}
	}
}

void	medium_sort(stack *stack_a, stack *stack_b, t_op **op_list)
{
	// 1. Schritt: Weise allen Elementen im Stack_A ihren korrekten Index zu!
	rank_stack(stack_a);

	// 2. Schritt: Pushe in intelligenten Chunks rüber nach B
	push_chunks_to_b(stack_a, stack_b, op_list);

	// 3. Schritt: Hole die Elemente perfekt sortiert zurück
	while (stack_b->size > 0)
	{
		bring_max_to_top(stack_b, op_list);
		pa(stack_a, stack_b);
		add_op(op_list, "pa");
	}
}
