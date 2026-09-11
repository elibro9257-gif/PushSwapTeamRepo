#include "push_swap.h"

void	push(stack *s1, stack *s2)
{
	t_list	*temp;

	if (!s2->data)
		return ;
	temp = s2->data;
	s2->data = s2->data->next;
	temp->next = s1->data;
	s1->data = temp;
	s2->size--;
	s1->size++;
}

void	pa(stack *a, stack *b, t_config *config)
{
	push(a, b);
	if (config->bench)
		a->bench->pa++;
	else
		write(1, "pa\n", 3);
}

void	pb(stack *a, stack *b, t_config *config)
{
	push(b, a);
	if (config->bench)
		b->bench->pb++;
	else
		write(1, "pb\n", 3);
}
