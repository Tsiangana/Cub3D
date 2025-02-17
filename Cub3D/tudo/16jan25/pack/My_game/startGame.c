/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startGame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:49:13 by pzau              #+#    #+#             */
/*   Updated: 2024/08/12 13:36:56 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*tela inicial*/
void	setup_level_window(t_vars *vars)
{
	t_dimensoes	dim;
	char		**map;

	vars->direction = 1;
	vars->moves = 0;
	vars->frame_count = 0;
	vars->current_screen = 1;
	dimention("game_assets/mapa/mapa2.ber", &dim);
	map = print_map("game_assets/mapa/mapa2.ber");
	vars->win_level = mlx_new_window(vars->mlx, dim.largura * PIX,
			dim.altura * PIX, "Nivel 1");
	vars->dim = dim;
	vars->map = map;
	load_imagens(vars);
	init_player_position(vars);
	mlx_hook(vars->win_level, 17, 0, close_level_one, vars);
	mlx_key_hook(vars->win_level, key_move_hook, vars);
	render_map(vars, map, dim);
	mlx_loop_hook(vars->mlx, (int (*)(void *))move_enemy, vars);
	ft_printf("  Altura: %d Largura: %d\n\n",
		dim.altura * PIX, dim.largura * PIX);
}

void	setup_level_two(t_vars *vars)
{
	t_dimensoes	dim;
	char		**map;

	vars->direction = 1;
	vars->moves = 0;
	vars->frame_count = 0;
	vars->current_screen = 1;
	dimention("game_assets/mapa/mapa1.ber", &dim);
	map = print_map("game_assets/mapa/mapa1.ber");
	vars->win_level_one = mlx_new_window(vars->mlx, dim.largura * PIX,
			dim.altura * PIX, "Nivel 2");
	vars->dim = dim;
	vars->map = map;
	load_imagens(vars);
	init_player_position(vars);
	mlx_hook(vars->win_level_one, 17, 0, cwlo, vars);
	mlx_key_hook(vars->win_level_one, key_move_hook_one, vars);
	render_map_one(vars, map, dim);
	mlx_loop_hook(vars->mlx, (int (*)(void *))move_enemy_one, vars);
	vars->coletaveis++;
	ft_printf("  Altura: %d Largura: %d\n\n",
		dim.altura * PIX, dim.largura * PIX);
}

void	setup_level_three(t_vars *vars)
{
	t_dimensoes	dim;
	char		**map;

	vars->direction = 1;
	vars->moves = 0;
	vars->frame_count = 0;
	vars->current_screen = 1;
	dimention("game_assets/mapa/mapa3.ber", &dim);
	map = print_map("game_assets/mapa/mapa3.ber");
	vars->win_level_two = mlx_new_window(vars->mlx, dim.largura * PIX,
			dim.altura * PIX, "Nivel 3");
	vars->dim = dim;
	vars->map = map;
	load_imagens(vars);
	init_player_position(vars);
	mlx_hook(vars->win_level_two, 17, 0, cwto, vars);
	mlx_key_hook(vars->win_level_two, key_move_hook_two, vars);
	render_map_two(vars, map, dim);
	mlx_loop_hook(vars->mlx, (int (*)(void *))move_enemy_two, vars);
	ft_printf("  Altura: %d Largura: %d\n\n",
		dim.altura * PIX, dim.largura * PIX);
}

void	waiting_page(t_vars *vars)
{
	vars->win_w = mlx_new_window(vars->mlx, 400, 300, "Waiting...");
	back_image_w(vars);
	mlx_put_image_to_window(vars->mlx, vars->win_w, vars->img_w, 0, 0);
}

void	levels_page(t_vars *vars)
{
	t_vals	vals;

	vars->current_screen = 0;
	vars->win_levels = mlx_new_window(vars->mlx, 900, 506, "Select Levels");
	back_image_levels(vars);
	mlx_put_image_to_window(vars->mlx, vars->win_levels, vars->img_level, 0, 0);
	mlx_hook(vars->win_levels, 17, 0, close_levels, vars);
	vals.level_one = mlx_xpm_file_to_image(vars->mlx,
			"gs/level1.xpm", &vals.level_one_width, &vals.level_one_height);
	vals.level_two = mlx_xpm_file_to_image(vars->mlx,
			"gs/level2.xpm", &vals.level_one_width, &vals.level_one_height);
	vals.level_three = mlx_xpm_file_to_image(vars->mlx,
			"gs/level3.xpm", &vals.level_one_width, &vals.level_one_height);
	buttons_start(vars, &vals);
	mlx_mouse_hook(vars->win_levels, mouse_click_levels, vars);
}
