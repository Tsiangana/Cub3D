NAME = game
CC = cc 
OBJ = $(SRC:.c=.o)

LFLAGS = -L./includes/mlx -lmlx -lXext -lX11 -lm -lz
INCLUDES = includes/mlx/libmlx.a
SRC = src/main.c\
		src/player.c

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
