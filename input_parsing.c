#include "values.h"

int	is_option(char *arg)
{
	if (!ft_strcmp(arg, "--bench"))
		return (1);
	if (!ft_strcmp(arg, "--simple"))
		return (1);
	if (!ft_strcmp(arg, "--medium"))
		return (1);
	if (!ft_strcmp(arg, "--complex"))
		return (1);
	if (!ft_strcmp(arg, "--adaptive"))
		return (1);
	return (0);
}

void	init_data(stack *a, stack *b, t_config *config)
{
	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;
	config->strategy = ADAPTIVE;
	config->bench = 0;
}

int	parse_input(char **argv, stack *a, t_config *config)
{
	int	index;

	if (is_option(argv[1]))
	{
		index = strategy_parsing(argv, config, 1);
		if (index == 0)
			return (0);
		index = number_parsing(argv, a, index);
	}
	else
	{
		index = number_parsing(argv, a, 1);
		if (index == 0)
			return (0);
		index = strategy_parsing(argv, config, index);
	}
	return (index);
}

int	validate_input(int index, int argc)
{
	if (index == 0)
		return (0);
	if (index != argc)
	{
		error();
		return (0);
	}
	return (1);
}


