/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:21:52 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 12:21:54 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int value, t_stack *a)
{
	t_list	*current;

	current = a->data;
	while (current)
	{
		if (current->content == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	add_to_stack(int value, t_stack *a)
{
	t_list	*new;
	t_list	*current;

	new = malloc(sizeof(t_list));
	if (!new)
		error();
	new->content = value;
	new->rank = 0;
	new->next = NULL;
	if (!a->data)
	{
		a->data = new;
		a->size++;
		return ;
	}
	current = a->data;
	while (current->next)
		current = current->next;
	current->next = new;
	a->size++;
}

int	number_parsing(char **argv, t_stack *a, int index)
{
	int	pos;
	int	value;
	int	error_flag;

	while (argv[index])
	{
		if (is_option(argv[index]))
			return (index);
		pos = 0;
		error_flag = 0;
		while (argv[index][pos])
		{
			value = check_integer(argv[index], &pos, &error_flag);
			if (error_flag)
				return (0);
			if (check_duplicate(value, a))
			{
				error();
				return (0);
			}
			add_to_stack(value, a);
		}
		index++;
	}
	return (index);
}
