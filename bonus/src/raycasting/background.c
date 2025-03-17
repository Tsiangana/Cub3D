/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:50:30 by pzau              #+#    #+#             */
/*   Updated: 2025/03/17 10:50:31 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->heightty)
	{
		x = 0;
		while (x < game->widthhy)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}

void	draw_background(t_game *game)
{
	int	sky_color;
	int	floor_color;
	int	y;
	int	x;

	sky_color = 0x000000;
	floor_color = 0x000000;
	y = 0;
	while (y < game->heightty / 2)
	{
		x = 0;
		while (x < game->widthhy)
		{
			put_pixel(x, y, sky_color, game);
			put_pixel(x, game->heightty - y - 1, floor_color, game);
			x++;
		}
		y++;
	}
}
