#include "values.h"

void	push(stack *s1, stack *s2)
{
	t_list	*temp;

	if(!s2->head)
		return ;
	temp = s2->head;
	s2->head = s2->head->next;

	temp->next = s1->head;
	s1->head = temp;
	s2->size--;
	s1->size++;
}

void	pa(stack *a, stack *b)
{
	push(a, b);
}

void	pb(stack *a, stack *b)
{
	push(b, a);
}
