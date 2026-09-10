#include "push_swap.h"
#include <unistd.h>

void	error(void)
{
	write(2, "Error\n", 6);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Hilfsfunktion: Speicher der Liste am Ende wieder freigeben
void	free_stack(stack *s)
{
	t_list	*current;
	t_list	*next;

	if (!s || !s->data)
		return ;
	current = s->data;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->data = NULL;
	s->size = 0;
}

int	main(int argc, char **argv)
{
	t_config	config;
	stack		a;
	stack		b;
	t_op		*op_list;
	int			index;

	if (argc < 2)
		return (0);
	op_list = NULL;
	init_data(&a, &b, &config);
	
	// 1. Parsing & Validierung deines Partners aufrufen
	index = parse_input(argv, &a, &config);
	if (!validate_input(index, argc))
	{
		free_stack(&a);
		return (0);
	}

	// 2. Sortier-Strategie basierend auf der Stack-Größe auswählen
	if (a.size <= 3)
		sort_three(&a, &op_list);
	else if (a.size <= 5)
		simple_sort(&a, &b, &op_list);
	else
		medium_sort(&a, &b, &op_list);

	// 3. Optimierung durchlaufen lassen und Befehle via write ausgeben
	optimize_operations(&op_list);
	print_and_free_ops(op_list);

	// 4. Clean-up
	free_stack(&a);
	free_stack(&b);
	return (0);
}

