/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:25:34 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/11 12:25:35 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		a;
	t_stack		b;
	t_bench		bench;
	double		disorder;

	if (argc < 2)
		return (0);
	init_program(&a, &b, &config, &bench);
	if (!parse_validate(argv, argc, &a, &config))
	{
		free_stacks(&a, &b);
		return (0);
	}
	disorder = compute_disorder(&a);
	if (disorder == 0.0)
	{
		if (config.bench)
			print_benchmark(a.bench, &config, disorder);
		free_stacks(&a, &b);
		return (0);
	}
	run_stratergy(&a, &b, &config, disorder);
	if (config.bench)
		print_benchmark(a.bench, &config, disorder);
	free_stacks(&a, &b);
	return (0);
}
