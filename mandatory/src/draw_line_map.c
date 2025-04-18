/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:18:01 by pzau              #+#    #+#             */
/*   Updated: 2025/01/25 12:18:02 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / game->block;
	y = py / game->block;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float y1, float y2, t_game *game)
{
	float	delta_x;
	float	dela_y;
	float	angle;
	float	fix_dist;

	delta_x = game->x2 - game->x1;
	dela_y = y2 - y1;
	angle = atan2(dela_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, dela_y) * cos(angle);
	return (fix_dist);
}

static void	aux_draw_line(t_player *player, t_game *game)
{
	if (touch(player->ray_x - player->cos_angle, player->ray_y, game))
	{
		if (player->ray_y > player->y)
			game->texture_index = 0;
		else
			game->texture_index = 1;
	}
	else
	{
		if (player->ray_x < player->x)
			game->texture_index = 2;
		else
			game->texture_index = 3;
	}
	game->x1 = player->x;
	game->x2 = player->ray_x;
	game->dist = fixed_dist(player->y, player->ray_y, game);
	game->heightt = (game->block / game->dist) * (game->widthyy / 2);
	game->start_y = (game->heightyy - game->heightt) / 2;
	game->end = game->start_y + game->heightt;
}

void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	int	tex_x;

	player->cos_angle = cos(start_x);
	player->sin_angle = sin(start_x);
	player->ray_x = player->x;
	player->ray_y = player->y;
	game->column = i;
	while (!touch(player->ray_x, player->ray_y, game))
	{
		if (game->debug)
			put_pixel(player->ray_x, player->ray_y, 0xFF0000, game);
		player->ray_x += player->cos_angle;
		player->ray_y += player->sin_angle;
	}
	if (!game->debug)
	{
		aux_draw_line(player, game);
		if (touch(player->ray_x - player->cos_angle, player->ray_y, game))
			tex_x = (int)player->ray_x % game->tex_width;
		else
			tex_x = (int)player->ray_y % game->tex_width;
		render_texture_column(game, game->start_y, game->end, tex_x);
	}
}
