/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 13:20:46 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 13:20:47 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_validate(char **argv, int argc,
				t_stack *a, t_config *config)
{
	int	index;

	index = parse_input(argv, a, config);
	return (validate_input(index, argc));
}

void	init_program(t_stack *a, t_stack *b, t_config *config, t_bench *bench)
{
	init_data(a, b, config);
	init_bench(bench);
	a->bench = bench;
	b->bench = bench;
}

void	run_stratergy(t_stack *a, t_stack *b, t_config *config, double disorder)
{
	if (config->strategy == COMPLEX)
		complex(a, b);
	else if (config->strategy == SIMPLE)
		simple_sort(a, b, NULL);
	else if (config->strategy == ADAPTIVE)
		adaptive(a, b, disorder);
	else if (config->strategy == MEDIUM)
		medium_sort(a, b, NULL);
}
