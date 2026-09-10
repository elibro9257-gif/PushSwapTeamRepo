#include "push_swap.h"

void	rr(stack *s)
{
	t_list	*temp;
	t_list	*prev;

	temp = s->data;
	if(!s->data || s->size < 2)
		return;
	while(temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	temp->next = s->data;
	prev->next = NULL;
	s->data = temp;
}

void	rra(stack *a)
{
	rr(a);
	printf("rra\n");
}

void	rrb(stack *b)
{
	rr(b);
	printf("rrb\n");
}

void	rrr(stack *a, stack *b)
{
	rr(a);
	rr(b);
	printf("rrr\n");
}
