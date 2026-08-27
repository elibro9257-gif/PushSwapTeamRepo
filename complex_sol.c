#include "push_swap.h"

void	assign_ranks(t_list *a)
{
	t_list	*i;
	t_list	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->content < i->content)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
}

static int	get_max_bits(int size)
{
	int	max_rank;
	int	bits;

	max_rank = size - 1;
	bits = 0;
	while (max_rank > 0)
	{
		max_rank >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_sort(stack *a, stack *b)
{
	int	bit;
	int	i;
	int	count;
	int	max_bits;

	max_bits = get_max_bits(a->size);
	bit = 0;
	while (bit < max_bits)
	{
		count = a->size;
		i = 0;
		while (i < count)
		{
			if (((a->data->rank >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}

void	complex(stack *a, stack *b)
{
	assign_ranks(a->data);
	radix_sort(a, b);
}
