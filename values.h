#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	int	content;
	struct s_list	*next;
}	t_list;

typedef struct STACK
{
	int	t_list	*data;
	int	size;
}	stack;

#endif
