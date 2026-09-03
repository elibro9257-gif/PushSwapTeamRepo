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

int     find_min_value(t_list *stack)
{
        int     min;

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

int     get_position(t_list *stack, int target_content)
{
        int     pos;

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

void    simple_sort(stack *stack_a, stack *stack_b, t_op **op_list)
{
//      int     size;
        int     min_val;
        int     pos;

        while (stack_a->size > 3)
        {
                min_val = find_min_value(stack_a->data);
                pos = get_position(stack_a->data, min_val);

                if (pos <= stack_a->size / 2)
                {
                        while (stack_a->data->content != min_val)
                        {
                                rotate_ra(stack_a);
                                add_op(op_list, "ra"); 
                        }
                }
                else
                {
                        while (stack_a->data->content != min_val)
                        {
                                rra(stack_a);
                                add_op(op_list, "rra"); 
                        }
                }

                pb(stack_a, stack_b);
                add_op(op_list, "pb");
        }

        sort_three(stack_a, op_list);

        while (stack_b->size > 0)
        {
                pa(stack_a, stack_b);
                add_op(op_list, "pa");
        }
}
                