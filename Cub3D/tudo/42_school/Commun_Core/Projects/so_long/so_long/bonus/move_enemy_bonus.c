/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 06:58:22 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 07:28:48 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	move_enemy_in_line(t_vars *vars, int y)
{
	int	x;
	int	new_x;

	x = 0;
	while (x < vars->dim.width_screen)
	{
		if (vars->map[y][x] == 'M')
		{
			new_x = x + vars->direction;
			if (new_x >= 0 && new_x < vars->dim.width_screen
				&& vars->map[y][new_x] == '0')
			{
				vars->map[y][x] = '0';
				vars->map[y][new_x] = 'M';
				x = new_x;
			}
			else if (new_x >= 0 && new_x < vars->dim.width_screen
				&& vars->map[y][new_x] == 'P')
			{
				close_x(vars);
			}
		}
		x++;
	}
}

void	process_enemy_movement(t_vars *vars)
{
	int	y;

	y = 0;
	while (y < vars->dim.height_screen)
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
	usleep(4000);
	vars->frame_count++;
	if (vars->frame_count < 100)
		return ;
	vars->frame_count = 0;
	process_enemy_movement(vars);
	update_enemy_direction(vars);
	render_map(vars, vars->map, vars->dim);
}
