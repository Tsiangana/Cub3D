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

# define BLOCK 64
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define PI 3.14159265359

# define ONE 49
# define TWO 50
# define CLOSE 65288
# define CLOSEBTN 65307

typedef struct s_game t_game;

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

    t_game *game;
}   t_player;

typedef struct s_texture
{
    void    *img;
    char    *addr;
    int     width;
    int     height;
    int     bpp;
    int     size_line;
    int     endian;
} t_texture;

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
    int height;
    int width;
    int DEBUG;
    char **map;

    t_texture  textures[4];
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
void    init_player(t_player *player, t_game *game);
void    draw_line_with_texture(t_player *player, t_game *game, float angle, int i);
void    show_grid(t_game *game, char value, int color);
void    move_player(t_player *player, t_game *game);
void    draw_line(t_player *player, t_game *game, float angle, int i);
void    show_square(int x, int y, int size, int color, t_game *game);
void	free_split(char **matriz);
void	open_get_size(char *mapa, t_game *game);
void	fill_matriz(char **matriz, char *s);
void    responsivo(t_game *game);
void    draw_background(t_game *game);
void    load_textures(t_game *game);
char	*get_nextline(char *str, t_bytes *bit);
char    **get_map(char *str);
char	**ft_split(char *s);
char	**alocate_matriz(int word);
char	*alocate_word(char *start, int len);
char	*alocate_space(char *content, char *buffer);
bool    touch(float px, float py, t_game *game);
int CloseWindow(t_game *game);
int draw_loop(t_game *game);
int get_texture_color(t_texture texture, int x, int y);
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_player *player);
int	delimeter(char c);
int	count_words(char *str);
float distance(float x, float y);
float fixed_dist(float x1, float y1, float x2, float y2, t_game *game);


/*-------------------*/
int get_texture_id(float ray_x, float ray_y, t_game *game);
int is_vertical_wall(float x, float y, t_game *game);

#endif
