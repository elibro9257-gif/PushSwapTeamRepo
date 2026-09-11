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
	fprintf(stderr, "Error\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_stack(t_stack *s)
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
	t_stack		a;
	t_stack		b;
	t_bench		bench;
	double		disorder;

	if (argc < 2)
		return (0);
	init_program(&a, &b, &config, &bench);
	if (!parse_validate(argv, argc, &a, &config))
		return (0);
	disorder = compute_disorder(&a);
	run_stratergy(&a, &b, &config, disorder);
	if (config.bench)
		print_benchmark(a.bench, &config, disorder);
	return (0);
}
