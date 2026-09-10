#include "push_swap.h"

void	push(stack *s1, stack *s2)
{
	t_list	*temp;

	if(!s2->data)
		return ;
	temp = s2->data;
	s2->data = s2->data->next;

	temp->next = s1->data;
	s1->data = temp;
	s2->size--;
	s1->size++;
}

void	pa(stack *a, stack *b)
{
	push(a, b);
	printf("pa\n");
}

void	pb(stack *a, stack *b)
{
	push(b, a);
	printf("pb\n");
}
