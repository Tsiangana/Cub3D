/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:21:29 by pzau              #+#    #+#             */
/*   Updated: 2024/08/12 17:16:48 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_level_coords(t_level_coords coords[3])
{
	coords[0].x_start = 205;
	coords[0].x_end = 353;
	coords[0].y_start = 223;
	coords[0].y_end = 280;
	coords[1].x_start = 380;
	coords[1].x_end = 521;
	coords[1].y_start = 256;
	coords[1].y_end = 280;
	coords[2].x_start = 549;
	coords[2].x_end = 692;
	coords[2].y_start = 229;
	coords[2].y_end = 279;
}

int	is_click_in_bounds(int x, int y, t_level_coords coords)
{
	int	within_x_bounds;
	int	within_y_bounds;

	within_x_bounds = (x >= coords.x_start && x <= coords.x_end);
	within_y_bounds = (y >= coords.y_start && y <= coords.y_end);
	return (within_x_bounds && within_y_bounds);
}

void	start_new_level(t_vars *vars, int index)
{
	destroy_level_page(vars);
	waiting_page(vars);
	back_image_w(vars);
	my_sleep();
	destroy_waiting(vars);
	if (index == 0)
		setup_level_window(vars);
	else if (index == 1)
		setup_level_two(vars);
	else if (index == 2)
		setup_level_three(vars);
}

void	process_level_clicks(int x, int y, t_vars *vars)
{
	t_level_coords	level_coords[3];
	int				i;

	init_level_coords(level_coords);
	i = 0;
	while (i < 3)
	{
		if (is_click_in_bounds(x, y, level_coords[i]))
		{
			start_new_level(vars, i);
			return ;
		}
		i++;
	}
}

int	mouse_click_levels(int buttons, int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (buttons == 1)
	{
		process_level_clicks(x, y, vars);
	}
	return (0);
}
