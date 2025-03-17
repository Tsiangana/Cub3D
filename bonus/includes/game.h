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

# include "./mlx/mlx.h"
# include "../libx/libx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

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
# define X 120
# define ENTER 65293

# define MARGIN 8
# define MINIMAP_SCALE 0.1

typedef struct s_game	t_game;

typedef struct s_minimap
{
	int	x;
	int	y;
	int	block_size;
	int	minimap_size;
	int	player_map_x;
	int	player_map_y;
	int	minimap_x;
	int	minimap_y;
	int	map_x;
	int	map_y;
	int	player_x;
	int	player_y;
}	t_mini;

typedef struct s_player
{
	t_game	*game;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
	float	x;
	float	y;
	float	angle;
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;
	float	angle_speed;
	float	new_x;
	float	new_y;
	int		speed;
}	t_player;

typedef struct s_pages
{
	void	*page[4];
	void	*buttons[4];
	void	*life;
	int		width[4];
	int		height[4];
	int		w_button[4];
	int		h_button[4];
	int		life_w;
	int		life_h;
}	t_pages;

typedef struct s_game
{
	t_player	player;
	t_pages		page;
	t_mini		minimap;
	void		*mlxs[4];
	void		*wins[4];
	void		*img;
	void		*textures[14];
	char		*data;
	char		**map;
	char		*tex_data[14];
	float		x1;
	float		x2;
	float		dist;
	float		heightt;
	int			bpp;
	int			size_line;
	int			endian;
	int			HEIGHT;
	int			WIDTH;
	int			height;
	int			width;
	int			DEBUG;
	int			live;
	int			tex_bpp[14];
	int			tex_sl[14];
	int			tex_end[14];
	int			tex_width;
	int			tex_height;
	int			block;
	int			tex_y;
	int			pix_color;
	int			start_y;
	int			end;
	int			hit_type;
	int			open;
	int			coin;
	int			coins;
	int			colig_x;
	int			colig_y;
	int			texture_index;
	int			tex_x;
	int			color;
	int			size;
}	t_game;

typedef struct s_bytes
{
	int	total_bytess;
}	t_bytes;

void	put_pixel(int x, int y, int color, t_game *game);
void	draw_square(int x, int y, int size, t_game *game);
void	draw_map(t_game *game);
void	clear_image(t_game *game);
void	init_player(t_player *player, t_game *game);
void	draw_line_with_texture(t_player *player, \
	t_game *game, float angle, int i);
void	show_grid(t_game *game, char value, int color);
void	move_player(t_player *player, t_game *game);
void	draw_line(t_player *player, t_game *game, float angle, int i);
void	show_square(int x, int y, int color, t_game *game);
void	free_split(char **matriz);
void	open_get_size(char *mapa, t_game *game);
void	fill_matriz(char **matriz, char *s);
void	responsivo(t_game *game);
void	draw_background(t_game *game);
void	load_textures(t_game *game);
void	showing_lives(t_game *game);
void	start_page_one(t_game *game, t_pages *pages);
void	draw_minimap(t_game *game);
void	put_letters(t_game *game);
void	render_texture_column(t_game *game, int column, int start_y, int end);
void	start_page_two(t_game *game);
void	init_player_pos(t_player *player, t_game *game);
void	page_three(t_game *game);
void	youwin(void);
void	level_one(t_game *game);
char	*get_nextline(char *str, t_bytes *bit);
char	**get_map(char *str);
char	**ft_split(char *s);
char	**alocate_matriz(int word);
char	*alocate_word(char *start, int len);
char	*alocate_space(char *content, char *buffer);
float	distance(float x, float y);
float	fixed_dist(float y1, float y2, t_game *game);
bool	touch(float px, float py, t_game *game);
bool	touch_aux(float px, float py, t_game *game);
int		CloseWindow(t_game *game);
int		draw_loop(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_player *player);
int		delimeter(char c);
int		count_words(char *str);
int		count_coins(char **map);
int		mouse_move(t_game *game);
int		CloseLevelOne(t_game *game);
int		start_button(int button, int x, int y, t_game *game);
int		CloseWindow(t_game *game);
int		Closet(t_game *game);

#endif
