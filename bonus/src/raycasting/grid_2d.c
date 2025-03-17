/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:26:03 by pzau              #+#    #+#             */
/*   Updated: 2025/01/27 10:26:04 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	show_grid(t_game *game, char value, int color)
{
	char	**map;
	int		y;
	int		x;

	map = game->map;
	game->color = color;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == value)
				draw_square(x * BLOCK, y * BLOCK, BLOCK, game);
			x++;
		}
		y++;
	}
}

void	show_square(int x, int y, int color, t_game *game)
	{
	int	i;
	int	j;

	i = 0;
	while (i < game->size)
	{
		j = 0;
		while (j < game->size)
		{
			put_pixel(x + j, y + i, color, game);
			j++;
		}
		i++;
	}
}
