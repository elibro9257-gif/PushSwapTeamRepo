#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int	content;
	int	rank;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*head;
	int	size;
}	stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

void	push(stack *s1, stack *s2);
void	pa(stack *a, stack *b);
void	pb(stack *a, stack *b);
void	swap(stack *s);
void	sa(stack *a);
void	sb(stack *b);
void	ss(stack *a, stack *b);
void	ro(stack *s);
void	ra(stack *a);
void	rb(stack *b);
void	rr(stack *a, stack *b);
void	ror(stack *s);
void	rra(stack *a);
void	rrb(stack *b);
void	rrr(stack *a, stack *b);
int	strategy_parsing(char **argv, t_config *config, int index);
void	init_data(stack *a, stack *b, t_config *config);
int	parse_input(char **argv, stack *a, t_config *config);
int	validate_input(int index, int argc);
int	check_duplicate(int value, stack *a);
void	add_to_stack(int value, stack *a);
int	number_parsing(char **argv, stack *a, int index);
void	complex(stack *a, stack *b);
int	check_integer(char *str, int *pos, int *error_flag);
int	set_error(int *error_flag);
int	get_sign(char *str, int *pos);
void	error();
int	is_option(char *arg);
int	ft_strcmp(const char *s1, const char *s2);
#endif
