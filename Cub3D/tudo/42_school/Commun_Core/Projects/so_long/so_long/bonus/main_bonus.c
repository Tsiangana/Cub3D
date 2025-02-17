/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:55:14 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 07:31:47 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	validate_map(char **map, t_dimensoes *dim, t_vars *vars)
{
	validate_rectangle(map, dim, vars);
	validate_player(map, dim, vars);
	validate_colector(map, dim, vars);
	validate_exit(map, dim, vars);
	check_map_playability(map, vars);
}

void	simple_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
}

int	main(int a, char **b)
{
	t_dimensoes	dim;
	t_vars		vars;

	vars.map = print_map(b[1]);
	dimention(b[1], &dim);
	vars.direction = 1;
	vars.moves = 0;
	vars.frame_count = 0;
	vars.dim = dim;
	validate_map(vars.map, &dim, &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, dim.width_screen * PIX,
			dim.height_screen * PIX, "so_long_bonus");
	mlx_hook(vars.win, 17, 0, close_x, &vars);
	load_imagens(&vars);
	init_player_position(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_move_hook, &vars);
	render_map(&vars, vars.map, dim);
	mlx_loop_hook(vars.mlx, (int (*)(void *))move_enemy, &vars);
	mlx_loop(vars.mlx);
	free_images(&vars);
	simple_destroy(&vars);
	close_x(&vars);
	free(vars.map);
	return (0);
}
