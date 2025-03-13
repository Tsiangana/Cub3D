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
	if (game->DEBUG == 0)
	{
		game->HEIGHT = 720;
		game->WIDTH = 1280;
	}
	if (game->DEBUG == 1 && ((game->height * 64 < 720)
			&& (game->width * 64 < 1280)))
	{
		game->HEIGHT = game->height * 64;
		game->WIDTH = game->width * 64;
	}
	if (game->DEBUG == 1 && ((game->height * 64 > 720)
			&& (game->width * 64 > 1280)))
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
	while (y < game->HEIGHT / 2)
	{
		x = 0;
		while (x < game->WIDTH)
		{
			put_pixel(x, y, sky_color, game);
			put_pixel(x, game->HEIGHT - y - 1, floor_color, game);
			x++;
		}
		y++;
	}
}
