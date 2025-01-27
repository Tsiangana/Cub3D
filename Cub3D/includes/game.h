/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:05:01 by pzau              #+#    #+#             */
/*   Updated: 2025/01/24 13:05:02 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "./mlx/mlx.h"
#include "../libx/libx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>

# define HEIGHT 720
# define WIDTH 1280
# define BLOCK 64
# define DEBUG 1
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define PI 3.14159265359

typedef struct s_player
{
    float x;
    float y;
    float angle;
    bool key_up;
    bool key_down;
    bool key_left;
    bool key_right;
    bool left_rotate;
    bool right_rotate;
}   t_player;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *data;
    int bpp;
    int size_line;
    int endian;
    int HEIGHT;
    int WIDTH;
    char **map;

    t_player    player;
}   t_game;

typedef struct s_bytes
{
	int	total_bytess;
}   t_bytes;

void    put_pixel(int x, int y, int color, t_game *game);
void    draw_square(int x, int y, int size, int color, t_game *game);
void    draw_map(t_game *game);
void    clear_image(t_game *game);
void    init_player(t_player *player);
void    show_grid(t_game *game, char value, int color);
void    move_player(t_player *player, t_game *game);
void    draw_line(t_player *player, t_game *game, float start_x, int i);
void    show_square(int x, int y, int size, int color, t_game *game);
void	free_split(char **matriz);
void	fill_matriz(char **matriz, char *s);
char	*get_nextline(char *str, t_bytes *bit);
char    **get_map(char *str);
char	**ft_split(char *s);
char	**alocate_matriz(int word);
char	*alocate_word(char *start, int len);
char	*alocate_space(char *content, char *buffer);
bool    touch(float px, float py, t_game *game);
int draw_loop(t_game *game);
int key_press(int keycode, t_player *player);
int key_release(int keycode, t_player *player);
int	delimeter(char c);
int	count_words(char *str);
float distance(float x, float y);
float fixed_dist(float x1, float y1, float x2, float y2, t_game *game);

#endif
