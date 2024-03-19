# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 18:25:17 by muribe-l          #+#    #+#              #
#    Updated: 2024/03/19 19:31:38 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
SOURCES = $(wildcard src/*.c)

OBJECTS = $(patsubst %.c,$(ODIR)/%.o,$(SOURCES))
ODIR = ./obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -Iincludes
RM = rm -rf
LIBFTNAME = libft.a
LIBFTDIR = ./libft

$(ODIR)/%.o: src/%.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFTDIR)/$(LIBFTNAME) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)
	make fclean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
