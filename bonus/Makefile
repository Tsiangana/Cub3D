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

NAME = cub3d
CC = cc 
OBJ = $(SRC:.c=.o)

LFLAGS = -L./../minilibx-linux -lmlx -lXext -lX11 -lm -lz
INCLUDES = ../minilibx-linux/libmlx.a
SRC = src/main.c\
		src/close.c\
		src/mensages.c\
		src/pages/page_one.c\
		src/pages/page_two.c\
		src/pages/page_three.c\
		src/pages/page_three_aux.c\
		src/levels/level_one.c\
		src/levels/aux.c\
		src/raycasting/draw_line_map.c\
		src/raycasting/draw_map.c\
		src/raycasting/get_textures.c\
		src/raycasting/grid_2d.c\
		src/raycasting/minimap.c\
		src/raycasting/coligion.c\
		src/raycasting/init_player.c\
		src/raycasting/background.c\
		src/raycasting/aux_draw_line.c\
		src/raycasting/print_sms_screen.c\
		src/raycasting/player.c\
		src/raycasting/screens.c\
		src/get_map/get_next_line.c\
		src/get_map/get_nextline.c\
		src/get_map/ft_split_aux.c\
		src/get_map/ft_split.c\
		libx/ft_strdup.c\
		libx/ft_strcat.c\
		libx/ft_strlen.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../minilibx-linux
	$(CC) $(SRC) -o $(NAME) $(INCLUDES) $(LFLAGS)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make clean -C ../minilibx-linux

clean:
	rm -rf $(OBJ)
	make clean -C ../minilibx-linux

re: fclean all

.PHONY: all fclean clean re
