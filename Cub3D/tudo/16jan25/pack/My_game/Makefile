# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzau <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/26 12:02:15 by pzau              #+#    #+#              #
#    Updated: 2024/07/28 19:29:05 by pzau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc

File = *.c

printf = my_printf/*.c

name = setup

mini = -L./minilibx -lmlx_Linux -lXext -lX11 -lm -o setup

all:
	$(cc) $(File) $(printf) $(mini) -o $(name)

clean:
	rm -r $(name)
