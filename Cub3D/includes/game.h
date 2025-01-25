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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

# define HEIGHT 720
# define WIDTH 1280
# define BLOCK 64
# define DEBUG 0
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
    t_player    player;

    char **map;
}   t_game;

void    put_pixel(int x, int y, int color, t_game *game);
void    draw_square(int x, int y, int size, int color, t_game *game);
void    init_game(t_game *game);
void    draw_map(t_game *game);
void    clear_image(t_game *game);
void    init_player(t_player *player);
void    move_player(t_player *player);
void    draw_line(t_player *player, t_game *game, float start_x, int i);
char    **get_map(void);
bool    touch(float px, float py, t_game *game);
int draw_loop(t_game *game);
int key_press(int keycode, t_player *player);
int key_release(int keycode, t_player *player);
float distance(float x, float y);
float fixed_dist(float x1, float y1, float x2, float y2, t_game *game);

#endif
