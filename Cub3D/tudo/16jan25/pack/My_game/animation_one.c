/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:05:23 by pzau              #+#    #+#             */
/*   Updated: 2024/08/12 11:50:11 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_enemy_in_line(t_vars *vars, int y)
{
	int	x;
	int	new_x;

	x = 0;
	while (x < vars->dim.largura)
	{
		if (vars->map[y][x] == 'M')
		{
			new_x = x + vars->direction;
			if (new_x >= 0 && new_x < vars->dim.largura
				&& vars->map[y][new_x] == '0')
			{
				vars->map[y][x] = '0';
				vars->map[y][new_x] = 'M';
				x = new_x;
			}
		}
		x++;
	}
}

void	process_enemy_movement(t_vars *vars)
{
	int	y;

	y = 0;
	while (y < vars->dim.altura)
	{
		move_enemy_in_line(vars, y);
		y++;
	}
}

void	update_enemy_direction(t_vars *vars)
{
	vars->moves++;
	if (vars->moves == 3)
	{
		vars->direction = -vars->direction;
		vars->moves = 0;
	}
}

void	move_enemy(t_vars *vars)
{
	if (vars->current_screen == 0)
		return ;
	usleep(4000);
	vars->frame_count++;
	if (vars->frame_count < 100)
		return ;
	vars->frame_count = 0;
	process_enemy_movement(vars);
	update_enemy_direction(vars);
	render_map(vars, vars->map, vars->dim);
}
