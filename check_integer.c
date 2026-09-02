#include "values.h"

int	check_integer(char *str, int *pos, int *error_flag)
{
	long	result;
	int		sign;

	while (str[*pos] == ' ' || str[*pos] == '\t')
		(*pos)++;
	sign = get_sign(str, pos);
	if (str[*pos] < '0' || str[*pos] > '9')
		return (set_error(error_flag));
	result = 0;
	while (str[*pos] >= '0' && str[*pos] <= '9')
	{
		result = result * 10 + (str[*pos] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (set_error(error_flag));
		(*pos)++;
	}
	while (str[*pos] == ' ' || str[*pos] == '\t')
		(*pos)++;
	return ((int)(result * sign));
}

int	set_error(int *error_flag)
{
	error();
	*error_flag = 1;
	return (0);
}

int	get_sign(char *str, int *pos)
{
	int	sign;

	sign = 1;
	if (str[*pos] == '+' || str[*pos] == '-')
	{
		if (str[*pos] == '-')
			sign = -1;
		(*pos)++;
	}
	return (sign);
}