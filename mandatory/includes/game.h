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

# include "../../minilibx-linux/mlx.h"
# include "../libx/libx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

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

# define MAX_LINE_LENGTH 1024
# define TAB_WIDTH 8

# define MARGIN 8

typedef struct s_game	t_game;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
	t_game	*game;
}	t_player;

typedef struct s_addtab
{
	int			y;
	int			x;
	int			j;
	char		*new_line;
	int			tab_count;
	int			new_len;
	int			k;
}				t_addtab;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*textures[4];
	char		*data;
	char		**map;
	char		*tex_data[4];
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*floor_color;
	char		*ceiling_color;
	char		**lines;
	float		x1;
	float		x2;
	float		dist;
	float		heightt;
	float		cos_angle;
	float		sin_angle;
	float		angle_speed;
	float		new_x;
	float		new_y;
	t_player	player;
	t_addtab	tab;
	int			speed;
	int			tex_bpp[4];
	int			tex_sl[4];
	int			tex_end[4];
	int			tex_width;
	int			tex_height;
	int			block;
	int			tex_y;
	int			pix_color;
	int			start_y;
	int			end;
	int			texture_index;
	int			color;
	int			size;
	int			column;
	int			bpp;
	int			size_line;
	int			endian;
	int			heightyy;
	int			widthyy;
	int			height;
	int			width;
	int			rows;
	int			cols;
	int			fd;
	int			y;
	int			x;
	int			x_p;
	int			y_p;
	int			color_f;
	int			color_c;
	int			debug;
}	t_game;

typedef struct s_bytes
{
	int	total_bytess;
}	t_bytes;

void	Validate_characters(t_game *game);
void	free_all(t_game *game);
void	initialize_game(t_game *game);
void	check_arguments(int ac, char **av, t_game *game);
void	parse_line(t_game *game, char *line);
void	validate_all(t_game *game);
void	add_tab(t_game *game);
void	aux_verifybreakline(char *str);
void	parse_game(t_game *game, char **lines);
void	verifybreakline(char *str);
void	validate_walls(t_game *game);
void	validate_zeros(t_game *game);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	aux_add_tab(t_game *game);
void	put_pixel(int x, int y, int color, t_game *game);
void	draw_square(int x, int y, int size, t_game *game);
void	draw_map(t_game *game);
void	clear_image(t_game *game);
void	render_texture_column(t_game *game, int start_y, int end, int tex_x);
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
void	init_player_pos(t_player *player, t_game *game);
void	load_textures(t_game *game);
char	*get_nextline(char *str, t_bytes *bit);
char	**get_map(char *str);
char	**ft_split(char *s);
char	**alocate_matriz(int word);
char	*alocate_word(char *start, int len);
char	*alocate_space(char *content, char *buffer);
char	*ft_strtrim(char const *s1, char const *set);
char	**parse_map(char **lines, int start_index);
char	*ft_strdup(char *str);
char	*validate_wall(t_game *game);
char	**ft_split_1(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*validate_zero(t_game *game);
char	*ft_strcat(char *dest, char *str);
char	**print_map(char *str);
char	*ft_strchr(const char *s, int c);
bool	touch(float px, float py, t_game *game);
float	distance(float x, float y);
float	fixed_dist(float y1, float y2, t_game *game);
int		closewindow(t_game *game);
int		draw_loop(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_player *player);
int		delimeter(char c);
int		count_words(char *str);
int		aux_verify_characters(int c);
int		ft_strlen(char *str);
int		verify_characters(t_game *game);
int		strlen_map(t_game *game);
int		ft_atoi(const char *nptr);
int		verify_extension(char *str);
int		is_valid_color(char *line);
int		get_color(char *line);
int		num_comma(char *line);
int		check_number(char *str);
int		verify_space(t_game *game);

#endif
