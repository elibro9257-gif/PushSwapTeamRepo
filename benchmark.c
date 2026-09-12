/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:21:22 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 12:21:24 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

long	total_operations(t_bench *bench)
{
	return (bench->sa + bench->sb + bench->ss
		+ bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr);
}

char	*strategy_name(t_config *config)
{
	if (config->strategy == SIMPLE)
		return ("Simple");
	if (config->strategy == MEDIUM)
		return ("Medium");
	if (config->strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*complexity_name(t_config *config, double disorder)
{
	if (config->strategy == SIMPLE)
		return ("O(n²)");
	if (config->strategy == MEDIUM)
		return ("O(n√n)");
	if (config->strategy == COMPLEX)
		return ("O(n log n)");
	if (disorder < 0.2)
		return ("O(n²)");
	if (disorder < 0.5)
		return ("O(n√n)");
	return ("O(n log n)");
}

void	print_benchmark(t_bench *bench, t_config *config,
			double disorder)
{
	long	total;

	total = total_operations(bench);
	print_disorder(disorder);
	print_strategy(config, disorder);
	putstr_fd("[bench] total_ops: ", 2);
	putlong_fd(total, 2);
	write(2, "\n", 1);
	print_basic_operations(bench);
	print_rotate_operations(bench);
}

