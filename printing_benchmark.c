#include "push_swap.h"

void	print_disorder(double disorder)
{
	long	value;
	long	whole;
	long	decimal;

	value = (long)(disorder * 10000);
	whole = value / 100;
	decimal = value % 100;
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
