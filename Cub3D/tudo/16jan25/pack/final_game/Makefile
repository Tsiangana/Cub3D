# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzau <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 09:12:48 by pzau              #+#    #+#              #
#    Updated: 2024/08/21 09:41:01 by pzau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = so_long

WAY = minilibx-linux


MINILIBF = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

SRC = files/main.c\

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(WAY)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MINILIBF)

clean:
	rm -r $(OBJ)
	make clean -C $(WAY)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean clean_b fclean fclean_b re re_b 
