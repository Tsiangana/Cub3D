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
		src/player.c\
		src/draw_line_map.c\
		src/draw_map.c\
		src/init_player_pos.c\
		src/grid_2d.c\
		src/screens.c\
		src/close.c\
		src/get_textures.c\
		src/get_map/get_next_line.c\
		src/get_map/get_nextline.c\
		src/get_map/ft_split_aux.c\
		src/get_map/ft_split.c\
		src/config_map.c\
		src/validations.c\
		src/aux_validations.c\
		src/init_main.c\
		src/validate_texture_color.c\
		src/validate_all.c\
		src/get_map/aux_func1.c\
		src/get_map/get_map.c\
		src/get_map/ft_strjoin.c\
		src/aux/ft_split_1.c\
		src/aux/ft_memcpy.c\
		src/aux/ft_strtrim.c\
		src/aux/ft_strchr.c\

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
