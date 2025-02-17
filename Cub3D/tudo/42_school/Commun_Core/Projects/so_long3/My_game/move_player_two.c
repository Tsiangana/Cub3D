/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:53:39 by pzau              #+#    #+#             */
/*   Updated: 2024/08/11 15:51:02 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	process_special_keys_one(int keycode, t_vars *vars)
{
	if (keycode == 65288)
	{
		mlx_destroy_window(vars->mlx, vars->win_level_one);
		levels_page(vars);
		return (1);
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win_level_one);
		exit(0);
	}
	return (0);
}

void	calculate_new_position_one(int keycode, int *new_x, int *new_y)
{
	if (keycode == 119)
		*new_y -= 1;
	else if (keycode == 115)
		*new_y += 1;
	else if (keycode == 97)
		*new_x -= 1;
	else if (keycode == 100)
		*new_x += 1;
}

void	process_map_interaction_one(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == 'C')
	{
		vars->coletaveis--;
	}
	if (vars->map[new_y][new_x] == 'M')
	{
		mlx_destroy_window(vars->mlx, vars->win_level_one);
		youlose();
		exit(0);
	}
	if (vars->map[new_y][new_x] == 'E' && vars->coletaveis == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win_level_one);
		setup_level_three(vars);
	}
	else if (vars->map[new_y][new_x] == 'E')
		ft_printf("  Ainda existem coletáveis no mapa\n\n");
	else
	{
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->x_pos = new_x;
		vars->y_pos = new_y;
		vars->map[vars->y_pos][vars->x_pos] = 'P';
		render_map_one(vars, vars->map, vars->dim);
	}
}

int	key_move_hook_one(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->x_pos;
	new_y = vars->y_pos;
	if (process_special_keys_one(keycode, vars))
		return (0);
	calculate_new_position_one(keycode, &new_x, &new_y);
	if (new_x >= 0 && new_x < vars->dim.largura && new_y >= 0
		&& new_y < vars->dim.altura && vars->map[new_y][new_x] != '1')
	{
		process_map_interaction_one(vars, new_x, new_y);
	}
	return (0);
}
