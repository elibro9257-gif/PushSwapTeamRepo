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
		current->rank = r; // Befüllt das einheitliche 'rank'-Feld
		current = current->next;
	}
}

