/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:34:03 by pzau              #+#    #+#             */
/*   Updated: 2025/01/31 12:34:04 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	responsivo(t_game *game)
{
	if (game->debug == 0)
	{
		game->heightyy = 720;
		game->widthyy = 1280;
	}
	if (game->debug == 1 && ((game->heightyy * 64 < 720)
			&& (game->widthyy * 64 < 1280)))
	{
		game->heightyy = game->heightyy * 64;
		game->widthyy = game->widthyy * 64;
	}
	if (game->debug == 1 && ((game->heightyy * 64 > 720)
			&& (game->widthyy * 64 > 1280)))
		printf("error\nmap too big to open in 2d mode\n");
}

void	draw_background(t_game *game)
{
	int	sky_color;
	int	floor_color;
	int	y;
	int	x;

	sky_color = 0x87CEEB;
	floor_color = 0x8B4513;
	y = 0;
	while (y < game->heightyy / 2)
	{
		x = 0;
		while (x < game->widthyy)
		{
			put_pixel(x, y, sky_color, game);
			put_pixel(x, game->heightyy - y - 1, floor_color, game);
			x++;
		}
		y++;
	}
}
