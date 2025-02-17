/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:59:12 by pzau              #+#    #+#             */
/*   Updated: 2024/08/13 06:11:20 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define PIX 50

# include "minilibx/mlx.h"
# include "my_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/Xlib.h>

typedef struct s_dimensoes
{
	int	altura;
	int	largura;
}	t_dimensoes;

typedef struct s_vars
{
	t_dimensoes	dim;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_w;
	void		*img_level;
	void		*start_img;
	void		*small_img;
	void		*bg_img;
	void		*win_level;
	void		*win_level_one;
	void		*win_level_two;
	void		*win_w;
	void		*win_levels;
	void		*img_0;
	void		*img_p;
	void		*img_c;
	void		*img_e;
	void		*img_wall;
	void		*img_enemy;
	char		**map;
	int			img_width;
	int			img_height;
	int			img_width_w;
	int			img_height_w;
	int			img_width_level;
	int			img_height_level;
	int			bg_width;
	int			bg_height;
	int			small_width;
	int			small_height;
	int			x_pos;
	int			y_pos;
	int			w_h_one;
	int			w_w_one;
	int			img_width_img;
	int			img_height_img;
	int			coletaveis;
	int			direction;
	int			moves;
	int			frame_count;
	int			current_screen;
	int			level_coords[3][4];
	int			last_y;
}		t_vars;

typedef struct s_level_coords
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;
}	t_level_coords;

typedef struct s_vals
{
	void	*level_one;
	void	*level_two;
	void	*level_three;
	int		level_one_width;
	int		level_one_height;
	int		level_one_x;
	int		level_one_y;
	int		level_two_x;
	int		level_two_y;
	int		level_three_x;
	int		level_three_y;
	int		pin_level;
}			t_vals;

void	gamestart(void);
void	gameend(void);
void	youwin(void);
void	youlose(void);
void	cleanup_all_resources(t_vars *vars);
void	destroy_level_windows(t_vars *vars);
void	destroy_window_and_images(t_vars *vars, void *win);
void	free_map(char **map);
void	draw_small_image(t_vars *vars);
void	setup_level_window(t_vars *vars);
void	setup_level_two(t_vars *vars);
void	destroy_main_window(t_vars *vars);
void	espera_tempo(int segundos);
void	waiting_page(t_vars *vars);
void	destroy_waiting(t_vars *vars);
void	mini_sleep_a(int segundos);
void	mini_sleep(void);
void	center_window(t_vars *vars, int window_width, int window_height);
void	disp_file(int fd, t_dimensoes *dim);
void	dimention(char *fdf, t_dimensoes *dim);
void	levels_page(t_vars *vars);
void	buttons_start(t_vars *vars, t_vals *vals);
void	destroy_level_page(t_vars *vars);
void	setup_level_three(t_vars *vars);
void	setup_level_two(t_vars *vars);
void	load_imagens(t_vars *vars);
void	render_map(t_vars *vars, char **map, t_dimensoes dim);
void	*get_image_for_cell(t_vars *vars, char cell);
void	render_map_line(t_vars *vars, char **map, int y, int largura);
void	render_map_one(t_vars *vars, char **map, t_dimensoes dim);
void	*get_image_for_cell_one(t_vars *vars, char cell);
void	render_map_line_one(t_vars *vars, char **map, int y, int largura);
void	init_player_position(t_vars *vars);
void	move_enemy(t_vars *vars);
void	move_enemy_in_line(t_vars *vars, int y);
void	process_enemy_movement(t_vars *vars);
void	process_map_level_three(t_vars *vars, int new_x, int new_y);
void	update_enemy_direction(t_vars *vars);
void	move_enemy_one(t_vars *vars);
void	move_enemy_in_line_one(t_vars *vars, int y);
void	process_enemy_movement_one(t_vars *vars);
void	update_enemy_direction_one(t_vars *vars);
void	move_enemy_two(t_vars *vars);
void	update_enemy_direction_two(t_vars *vars);
void	process_enemy_movement_two(t_vars *vars);
void	move_enemy_in_line_two(t_vars *vars, int y);
void	process_map_level_two(t_vars *vars, int new_x, int new_y);
void	calculate_new_pos_level_two(int keycode, int *new_x, int *new_y);
void	calculate_new_position(int keycode, int *new_x, int *new_y);
void	process_map_interaction(t_vars *vars, int new_x, int new_y);
void	calculate_new_position_one(int keycode, int *new_x, int *new_y);
void	process_map_interaction_one(t_vars *vars, int new_x, int new_y);
void	render_map_two(t_vars *vars, char **map, t_dimensoes dim);
void	*get_image_for_cell_two(t_vars *vars, char cell);
void	render_map_line_two(t_vars *vars, char **map, int y, int largura);
void	process_level_clicks(int x, int y, t_vars *vars);
void	init_level_coords(t_level_coords coords[3]);
void	handle_collectable(t_vars *vars, int new_x, int new_y);
void	handle_loss(t_vars *vars);
void	handle_win(t_vars *vars);
void	update_player_position(t_vars *vars, int new_x, int new_y);
void	process_map_level_two(t_vars *vars, int new_x, int new_y);
void	start_new_level(t_vars *vars, int index);
void	process_level_clicks(int x, int y, t_vars *vars);
void	exit_function(void);
char	**print_map(const char *filename);
char	*ft_strncpy(char *s1, char *s2, int n);
char	**ft_split(char *str);
int		is_click_in_bounds(int x, int y, t_level_coords coords);
int		process_special_keys(int keycode, t_vars *vars);
int		process_special_keys_one(int keycode, t_vars *vars);
int		handle_special_keys_level_two(int keycode, t_vars *vars);
int		back_image(t_vars *vars);
int		init_image(t_vars *vars);
int		iniciar(int button, int x, int y, t_vars *vars);
int		close_level_one(void *param);
int		back_image_w(t_vars *vars);
int		my_sleep(void);
int		back_image_levels(t_vars *vars);
int		close_levels(void *param);
int		mouse_click_levels(int button, int x, int y, void *param);
int		cwlo(void *param);
int		cwto(void *param);
int		key_esc(int keycode, void *param);
int		close_new_window(void *param);
int		key_back_one(int keycode, void *param);
int		key_back_two(int keycode, void *param);
int		key_back_three(int keycode, void *param);
int		key_move_hook(int keycode, t_vars *vars);
int		key_move_hook_one(int keycode, t_vars *vars);
int		key_move_hook_two(int keycode, t_vars *vars);

#endif
