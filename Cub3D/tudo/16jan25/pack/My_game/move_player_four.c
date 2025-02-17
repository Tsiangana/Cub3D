/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:23:20 by pzau              #+#    #+#             */
/*   Updated: 2024/08/11 18:35:27 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_collectable(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == 'C')
	{
		vars->coletaveis--;
	}
}

void	handle_loss(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win_level_two);
	youlose();
	exit(0);
}

void	handle_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win_level_two);
	youwin();
	exit(0);
}

void	update_player_position(t_vars *vars, int new_x, int new_y)
{
	vars->map[vars->y_pos][vars->x_pos] = '0';
	vars->x_pos = new_x;
	vars->y_pos = new_y;
	vars->map[vars->y_pos][vars->x_pos] = 'P';
	render_map_two(vars, vars->map, vars->dim);
}

void	process_map_level_two(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == 'C')
	{
		handle_collectable(vars, new_x, new_y);
	}
	else if (vars->map[new_y][new_x] == 'M')
	{
		handle_loss(vars);
	}
	else if (vars->map[new_y][new_x] == 'E')
	{
		if (vars->coletaveis == 0)
		{
			handle_win(vars);
		}
		else
		{
			ft_printf("  Ainda existem coletaveis no mapa\n\n");
		}
	}
	else
	{
		update_player_position(vars, new_x, new_y);
	}
}
