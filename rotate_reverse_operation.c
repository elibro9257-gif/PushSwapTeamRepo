#include "values.h"

void	rr(stack *s)
{
	t_list	*temp;
	t_list	*prev;

	temp = s->head;
	if(!s->head || s->size < 2)
		return;
	while(temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	temp->next = s->head;
	prev->next = NULL;
	s->head = temp;
}

void	rra(stack *a)
{
	rr(a);
}

void	rrb(stack *b)
{
	rr(b);
}

void	rrr(stack *a, stack *b)
{
	rr(a);
	rr(b);
}
