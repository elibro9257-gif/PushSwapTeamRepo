/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:25:00 by ebroeker          #+#    #+#             */
/*   Updated: 2026/09/11 12:40:00 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_nodes(t_op **head, t_op *first, t_op *second)
{
	if (first->prev)
		first->prev->next = second->next;
	else
		*head = second->next;
	if (second->next)
		second->next->prev = first->prev;
	free(first);
	free(second);
}

void	combine_nodes(t_op *first, t_op *second, char *new_cmd)
{
	first->cmd = new_cmd;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	free(second);
}

static int	is_cancel_op(char *c, char *n)
{
	if ((ft_strcmp(c, "ra") == 0 && ft_strcmp(n, "rra") == 0)
		|| (ft_strcmp(c, "rra") == 0 && ft_strcmp(n, "ra") == 0)
		|| (ft_strcmp(c, "rb") == 0 && ft_strcmp(n, "rrb") == 0)
		|| (ft_strcmp(c, "rrb") == 0 && ft_strcmp(n, "rb") == 0)
		|| (ft_strcmp(c, "pa") == 0 && ft_strcmp(n, "pb") == 0)
		|| (ft_strcmp(c, "pb") == 0 && ft_strcmp(n, "pa") == 0))
		return (1);
	return (0);
}

static int	check_combine_ops(t_op *curr, t_op *next)
{
	if ((ft_strcmp(curr->cmd, "ra") == 0 && ft_strcmp(next->cmd, "rb") == 0)
		|| (ft_strcmp(curr->cmd, "rb") == 0
			&& ft_strcmp(next->cmd, "ra") == 0))
		return (combine_nodes(curr, next, "rr"), 1);
	if ((ft_strcmp(curr->cmd, "rra") == 0
			&& ft_strcmp(next->cmd, "rrb") == 0)
		|| (ft_strcmp(curr->cmd, "rrb") == 0
			&& ft_strcmp(next->cmd, "rra") == 0))
		return (combine_nodes(curr, next, "rrr"), 1);
	if ((ft_strcmp(curr->cmd, "sa") == 0 && ft_strcmp(next->cmd, "sb") == 0)
		|| (ft_strcmp(curr->cmd, "sb") == 0
			&& ft_strcmp(next->cmd, "sa") == 0))
		return (combine_nodes(curr, next, "ss"), 1);
	return (0);
}

int	check_cancel_and_combine(t_op **head, t_op **curr, t_op *next)
{
	t_op	*p;

	if (is_cancel_op((*curr)->cmd, next->cmd))
	{
		p = (*curr)->prev;
		delete_nodes(head, *curr, next);
		if (p)
			*curr = p;
		else
			*curr = *head;
		return (1);
	}
	return (check_combine_ops(*curr, next));
}
