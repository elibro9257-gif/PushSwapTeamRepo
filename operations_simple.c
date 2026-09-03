#include "push_swap.h"

void	push(stack *s1, stack *s2)
{
	t_list	*tmp;

	if (!s2 || !s2->data)
		return ;
	tmp = s2->data;
	s2->data = s2->data->next;
	s2->size--;
	tmp->next = s1->data;
	s1->data = tmp;
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

void	rra(stack *a)
{
	t_list	*prev;
	t_list	*current;

	if (!a || !a->data || !a->data->next)
		return ;
	prev = NULL;
	current = a->data;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = a->data;
	a->data = current;
}

void	sort_three(stack *a, t_op **op_list)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->data->content;
	second = a->data->next->content;
	third = a->data->next->next->content;
	if (first > second && second < third && first < third)
	{
		swap_sa(a);
		add_op(op_list, "sa");
	}
	else if (first > second && second > third && first > third)
	{
		swap_sa(a);
		add_op(op_list, "sa");
		rra(a);
		add_op(op_list, "rra");
	}
	else if (first > second && second < third && first > third)
	{
		rotate_ra(a);
		add_op(op_list, "ra");
	}
	else if (first < second && second > third && first < third)
	{
		swap_sa(a);
		add_op(op_list, "sa");
		rotate_ra(a);
		add_op(op_list, "ra");
	}
	else if (first < second && second > third && first > third)
	{
		rra(a);
		add_op(op_list, "rra");
	}
}

