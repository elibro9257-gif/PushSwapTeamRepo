#include "values.h"

int	check_duplicate(int value, stack *a)
{
	t_list	*current;

	current = a->head;
	while (current)
	{
		if (current->content == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	add_to_stack(int value, stack *a)
{
	t_list	*new;
	t_list	*current;

	new = malloc(sizeof(t_list));
	if (!new)
		error();
	new->content = value;
	new->rank = 0;
	new->next = NULL;
	if (!a->head)
	{
		a->head = new;
		a->size++;
		return ;
	}
	current = a->head;
	while (current->next)
		current = current->next;
	current->next = new;
	a->size++;
}

int	number_parsing(char **argv, stack *a, int index)
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