/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:26:24 by pzau              #+#    #+#             */
/*   Updated: 2024/08/12 13:21:23 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*get_image_for_cell_two(t_vars *vars, char cell)
{
	if (cell == '1')
		return (vars->img_0);
	else if (cell == 'P')
		return (vars->img_p);
	else if (cell == 'C')
		return (vars->img_c);
	else if (cell == 'E')
		return (vars->img_e);
	else if (cell == '0')
		return (vars->img_wall);
	else if (cell == 'M')
		return (vars->img_enemy);
	return (NULL);
}

void	render_map_line_two(t_vars *vars, char **map, int y, int largura)
{
	void	*img;
	int		x;
	char	cell;

	x = 0;
	while (x < largura)
	{
		cell = map[y][x];
		img = get_image_for_cell_two(vars, cell);
		if (img)
			mlx_put_image_to_window(vars->mlx, vars->win_level_two,
				img, x * PIX, y * PIX);
		x++;
	}
}

void	render_map_two(t_vars *vars, char **map, t_dimensoes dim)
{
	int	y;

	y = 0;
	while (y < dim.altura)
	{
		render_map_line_two(vars, map, y, dim.largura);
		y++;
	}
}
