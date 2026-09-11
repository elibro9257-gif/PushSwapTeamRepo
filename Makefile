# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebroeker <ebroeker@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/10 10:30:00 by ebroeker          #+#    #+#              #
#    Updated: 2026/09/10 10:36:36 by ebroeker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Alle deine exakten Dateinamen aufeinander abgestimmt:
SRCS        = main.c \
              check_integer.c \
              complex_sol.c \
              input_parsing.c \
              medium_sort.c \
              number_parser.c \
              operations_simple.c \
              optimization.c \
              push_operation.c \
              rank_stack.c \
              rotate.c \
              rotate_reverse_operation.c \
              simple_sort.c \
              stratergy_parser.c \
              swap.c \
              adaptive.c \
              benchmark.c  

# Automatische Erstellung der .o Dateinamen
OBJS        = $(SRCS:.c=.o)

# Visuelles Feedback fürs Terminal
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Kompiliere $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) erfolgreich erstellt!$(RESET)"

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)Object-Dateien gelöscht.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) gelöscht.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
