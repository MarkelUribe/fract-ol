# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 18:25:17 by muribe-l          #+#    #+#              #
#    Updated: 2024/04/22 12:59:25 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
SOURCES = src/fract-ol.c src/free.c src/init.c src/render.c src/utils.c src/events.c

OBJECTS = $(SOURCES:%.c=%.o)
ODIR = ./src/obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o2 -Iincludes
MLX_LIB = libs/mlx/
MLX_FLAGS = -L libs/mlx/ -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFTNAME = libft.a
LIBFTDIR = ./libs/libft

$(ODIR)/%.o: src/%.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C $(MLX_LIB)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_FLAGS) $(LIBFTDIR)/$(LIBFTNAME) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)
	make fclean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
