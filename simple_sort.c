/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:45:29 by ebroeker          #+#    #+#             */
/*   Updated: 2026/08/17 18:48:41 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_value(t_list *stack)
{
    int min;

    if (!stack)
        return (0);
    min = stack->content;
    while (stack)
    {
        if (stack->content < min)
            min = stack->content;
        stack = stack->next;
    }
    return (min);
}

int get_position(t_list *stack, int target_content)
{
    int pos;

    pos = 0;
    while (stack)
    {
        if (stack->content == target_content)
            return (pos);
        pos++;
        stack = stack->next;
    }
    return (pos);
}

/*
** Hilfsfunktion, um das kleinste Element an die Spitze von Stack A zu bringen
*/
static void bring_min_to_top(stack *stack_a, int min_val, int pos,
                                t_op **op_list, t_config *config)
{
    if (pos <= stack_a->size / 2)
    {
        while (stack_a->data->content != min_val)
        {
            rotate_ra(stack_a, config);
            add_op(op_list, "ra");
        }
    }
    else
    {
        while (stack_a->data->content != min_val)
        {
            rra(stack_a, config);
            add_op(op_list, "rra");
        }
    }
}

void    simple_sort(stack *stack_a, stack *stack_b, t_op **op_list, t_config *config)
{
    int min_val;
    int pos;

    while (stack_a->size > 3)
    {
        min_val = find_min_value(stack_a->data);
        pos = get_position(stack_a->data, min_val);
        bring_min_to_top(stack_a, min_val, pos, op_list, config);
        pb(stack_a, stack_b, config);
        add_op(op_list, "pb");
    }
    sort_three(stack_a, op_list, config);
    while (stack_b->size > 0)
    {
        pa(stack_a, stack_b, config);
        add_op(op_list, "pa");
    }
}
