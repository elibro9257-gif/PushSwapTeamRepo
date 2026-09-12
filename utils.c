#include "push_swap.h"

void	putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	putlong_fd(long n, int fd)
{
	char	c;

	if (n == -2147483648L)
	{
		putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putlong_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
