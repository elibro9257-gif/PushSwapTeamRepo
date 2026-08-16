# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/16 19:07:21 by ebroeker          #+#    #+#              #
#    Updated: 2026/08/16 19:11:03 by ebroeker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		cc
CFLAGS = 	-Wall -Wextra -Werror
AR =		ar
ARFLAGS =	rcs

NAME =		push_swap.a

SRC =		swap.c \

OBJ =		$(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
