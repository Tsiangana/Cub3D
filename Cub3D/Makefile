# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzau <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 13:04:38 by pzau              #+#    #+#              #
#    Updated: 2025/01/24 13:04:40 by pzau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game
CC = cc 
OBJ = $(SRC:.c=.o)

LFLAGS = -L./includes/mlx -lmlx -lXext -lX11 -lm -lz
INCLUDES = includes/mlx/libmlx.a
SRC = src/main.c\
		src/player.c\
		src/draw_line_map.c\
		src/draw_map.c\
		src/grid_2d.c\
		src/get_map/get_next_line.c\
		src/get_map/get_nextline.c\
		src/get_map/ft_split_aux.c\
		src/get_map/ft_split.c\
		libx/ft_strdup.c\
		libx/ft_strcat.c\
		libx/ft_strlen.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./includes/mlx
	$(CC) $(SRC) -o $(NAME) $(INCLUDES) $(LFLAGS)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make clean -C ./includes/mlx

clean:
	rm -rf $(OBJ)
	make clean -C ./includes/mlx

re: fclean all

.PHONY: all fclean clean re
