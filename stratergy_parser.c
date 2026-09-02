#include "values.h"

static int	set_strategy(char *arg, t_config *config)
{
	if (!ft_strcmp(arg, "--simple"))
		config->strategy = SIMPLE;
	else if (!ft_strcmp(arg, "--medium"))
		config->strategy = MEDIUM;
	else if (!ft_strcmp(arg, "--complex"))
		config->strategy = COMPLEX;
	else if (!ft_strcmp(arg, "--adaptive"))
		config->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	duplicate_checker(char *temp, t_config *config,
				int *strat_selector)
{
	if (!ft_strcmp(temp, "--bench"))
	{
		if (config->bench)
		{
			error();
			return (-1);
		}
		config->bench = 1;
		return (1);
	}
	if (set_strategy(temp, config))
	{
		if (*strat_selector)
		{
			error();
			return (-1);
		}
		*strat_selector = 1;
		return (1);
	}
	return (0);
}

int	strategy_parsing(char **argv, t_config *config, int index)
{
	int	i;
	int	strat_selector;
	int	result;

	i = index;
	strat_selector = 0;
	while (argv[i])
	{
		result = duplicate_checker(argv[i], config, &strat_selector);
		if (result == -1)
			return (0);
		if (result == 0)
			break ;
		i++;
	}
	return (i);
}