/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:13:12 by pzau              #+#    #+#             */
/*   Updated: 2024/08/12 17:17:35 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	process_special_keys(int keycode, t_vars *vars)
{
	if (keycode == 65288)
	{
		mlx_destroy_window(vars->mlx, vars->win_level);
		ft_printf("  Regressando à tela dos níveis\n\n");
		levels_page(vars);
		return (1);
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win_level);
		exit(0);
	}
	return (0);
}

void	calculate_new_position(int keycode, int *new_x, int *new_y)
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

void	process_map_interaction(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == 'C')
	{
		vars->coletaveis--;
	}
	if (vars->map[new_y][new_x] == 'M')
	{
		mlx_destroy_window(vars->mlx, vars->win_level);
		youlose();
		exit(0);
	}
	if (vars->map[new_y][new_x] == 'E' && vars->coletaveis == 0)
	{
		mlx_destroy_window(vars->mlx, vars->win_level);
		setup_level_two(vars);
	}
	else if (vars->map[new_y][new_x] == 'E')
		ft_printf("  Ainda existem coletáveis no mapa\n\n");
	else
	{
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->x_pos = new_x;
		vars->y_pos = new_y;
		vars->map[vars->y_pos][vars->x_pos] = 'P';
		render_map(vars, vars->map, vars->dim);
	}
}

int	key_move_hook(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->x_pos;
	new_y = vars->y_pos;
	if (process_special_keys(keycode, vars))
		return (0);
	calculate_new_position(keycode, &new_x, &new_y);
	if (new_x >= 0 && new_x < vars->dim.largura && new_y >= 0
		&& new_y < vars->dim.altura && vars->map[new_y][new_x] != '1')
	{
		process_map_interaction(vars, new_x, new_y);
	}
	return (0);
}
