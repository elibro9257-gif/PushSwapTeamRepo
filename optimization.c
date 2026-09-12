/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:23:59 by ebroeker          #+#    #+#             */
/*   Updated: 2026/09/11 12:25:00 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_op(t_op **head, char *cmd)
{
	t_op	*new_node;
	t_op	*last;

	if (!head)
		return (0);
	new_node = malloc(sizeof(t_op));
	if (!new_node)
		return (0);
	new_node->cmd = cmd;
	new_node->next = NULL;
	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (1);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return (1);
}

void	optimize_operations(t_op **head)
{
	t_op	*curr;
	t_op	*next;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr && curr->next)
	{
		next = curr->next;
		if (check_cancel_and_combine(head, &curr, next))
			continue ;
		curr = curr->next;
	}
}

void	print_and_free_ops(t_op *head)
{
	t_op	*tmp;
	int		len;

	while (head)
	{
		tmp = head->next;
		len = 0;
		while (head->cmd[len])
			len++;
		write(1, head->cmd, len);
		write(1, "\n", 1);
		free(head);
		head = tmp;
	}
}
