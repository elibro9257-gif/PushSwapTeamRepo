#include "push_swap.h"

double	compute_disorder(stack *a)
{
	t_list	*current;
	t_list	*compare;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = a->data;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->content > compare->content)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}

void	adaptive(stack *a, stack *b, t_config *config, double disorder)
{
	if (disorder < 0.2)
		simple_sort(a, b, NULL, config);
	else if (disorder < 0.5)
		medium_sort(a, b, NULL, config);
	else
		complex(a, b, config);
}
