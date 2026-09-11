#include "push_swap.h"

void	error()
{
	printf("Error\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_stack(stack *s)
{
	t_list	*current;

	current = s->data;
	printf("Stack (size: %d):\n", s->size);
	while (current)
	{
		printf("content: %d | rank: %d\n",
			current->content, current->rank);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_config	config;
	stack		a;
	stack		b;
	int			index;

	if (argc < 2)
		return (0);
	init_data(&a, &b, &config);
	index = parse_input(argv, &a, &config);
	if (!validate_input(index, argc))
		return (0);
	if (config.strategy == COMPLEX)
		complex(&a, &b);
	else if (config.strategy == SIMPLE)
		simple_sort(&a, &b, NULL);
	else if (config.strategy == ADAPTIVE)
		adaptive(&a, &b);
	else if (config.strategy == MEDIUM)
		medium_sort(&a, &b, NULL);
	print_stack(&a);
	print_stack(&b);
	return (0);
}
