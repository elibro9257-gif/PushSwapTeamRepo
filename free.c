#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack)
		return ;
	current = stack->data;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->data = NULL;
	stack->size = 0;
}