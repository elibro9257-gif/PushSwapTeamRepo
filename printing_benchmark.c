/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_benchmark.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sturuvek <sturuvek@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:27:06 by sturuvek          #+#    #+#             */
/*   Updated: 2026/09/12 13:27:07 by sturuvek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(double disorder)
{
	long	percent;
	long	whole;
	long	decimal;

	percent = (long)(disorder * 10000.0);
	whole = percent / 100;
	decimal = percent % 100;
	putstr_fd("[bench] disorder: ", 2);
	putlong_fd(whole, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	putlong_fd(decimal, 2);
	putstr_fd("%\n", 2);
}

void	print_strategy(t_config *config, double disorder)
{
	putstr_fd("[bench] strategy: ", 2);
	putstr_fd(strategy_name(config), 2);
	putstr_fd(" / ", 2);
	putstr_fd(complexity_name(config, disorder), 2);
	write(2, "\n", 1);
}

void	print_basic_operations(t_bench *bench)
{
	putstr_fd("[bench] sa: ", 2);
	putlong_fd(bench->sa, 2);
	putstr_fd(" sb: ", 2);
	putlong_fd(bench->sb, 2);
	putstr_fd(" ss: ", 2);
	putlong_fd(bench->ss, 2);
	putstr_fd(" pa: ", 2);
	putlong_fd(bench->pa, 2);
	putstr_fd(" pb: ", 2);
	putlong_fd(bench->pb, 2);
	write(2, "\n", 1);
}

void	print_rotate_operations(t_bench *bench)
{
	putstr_fd("[bench] ra: ", 2);
	putlong_fd(bench->ra, 2);
	putstr_fd(" rb: ", 2);
	putlong_fd(bench->rb, 2);
	putstr_fd(" rr: ", 2);
	putlong_fd(bench->rr, 2);
	putstr_fd(" rra: ", 2);
	putlong_fd(bench->rra, 2);
	putstr_fd(" rrb: ", 2);
	putlong_fd(bench->rrb, 2);
	putstr_fd(" rrr: ", 2);
	putlong_fd(bench->rrr, 2);
	write(2, "\n", 1);
}
