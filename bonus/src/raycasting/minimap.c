/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:48:05 by pzau              #+#    #+#             */
/*   Updated: 2025/03/17 10:48:06 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	init_minimap(t_game *game)
{
	game->minimap.block_size = game->block * MINIMAP_SCALE;
	game->minimap.minimap_size = 6;
	game->minimap.player_map_x = game->player.x / game->block;
	game->minimap.player_map_y = game->player.y / game->block;
	game->minimap.minimap_x = game->widthhy - (game->minimap.minimap_size
			* game->minimap.block_size) - 20;
	game->minimap.minimap_y = 20;
	game->minimap.x = 0;
	game->minimap.y = 0;
	game->minimap.y = -game->minimap.minimap_size / 2;
}

static void	condition_minimap(t_game *game)
{
	game->size = game->minimap.block_size;
	if (game->minimap.map_x >= 0 && game->minimap.map_y >= 0
		&& game->map[game->minimap.map_y]
		&& game->map[game->minimap.map_y][game->minimap.map_x])
	{
		if (game->map[game->minimap.map_y][game->minimap.map_x] == '1')
			show_square(game->minimap.minimap_x
				+ (game->minimap.x + game->minimap.minimap_size / 2)
				* game->minimap.block_size, game->minimap.minimap_y
				+ (game->minimap.y + game->minimap.minimap_size / 2)
				* game->minimap.block_size,
				0xFFFFFF, game);
		else
			show_square(game->minimap.minimap_x + (game->minimap.x
					+ game->minimap.minimap_size / 2)
				* game->minimap.block_size, game->minimap.minimap_y
				+ (game->minimap.y + game->minimap.minimap_size / 2)
				* game->minimap.block_size,
				0x1388ef, game);
	}
}

void	draw_minimap(t_game *game)
{
	init_minimap(game);
	game->color = 0xFF0000;
	while (game->minimap.y < game->minimap.minimap_size / 2)
	{
		game->minimap.x = -game->minimap.minimap_size / 2;
		while (game->minimap.x < game->minimap.minimap_size / 2)
		{
			game->minimap.map_x = game->minimap.player_map_x + game->minimap.x;
			game->minimap.map_y = game->minimap.player_map_y + game->minimap.y;
			condition_minimap(game);
			game->minimap.x++;
		}
		game->minimap.y++;
	}
	game->minimap.player_x = game->minimap.minimap_x
		+ (game->minimap.minimap_size / 2) * game->minimap.block_size;
	game->minimap.player_y = game->minimap.minimap_y
		+ (game->minimap.minimap_size / 2) * game->minimap.block_size;
	draw_square(game->minimap.player_x - 2, game->minimap.player_y
		- 2, 5, game);
}
