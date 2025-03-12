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

#include "../../includes/game.h"

static int	value_coin(t_game *game)
{
	game->coin++;
	if (game->coin >= 0 && game->coin <= 300)
		return (5);
	else if (game->coin >= 301 && game->coin <= 600)
		return (6);
	else if (game->coin >= 601 && game->coin <= 900)
		return (7);
	else if (game->coin >= 901 && game->coin <= 1200)
		return (8);
	else if (game->coin >= 1201 && game->coin <= 1500)
		return (9);
	else if (game->coin >= 1501 && game->coin <= 1800)
		return (10);
	else if (game->coin >= 1801 && game->coin <= 2100)
		return (11);
	else if (game->coin >= 2101 && game->coin <= 2400)
		return (12);
	else if (game->coin >= 2401 && game->coin <= 2800)
	{
		game->coin = 0;
		return (13);
	}
	return (5);
}


bool    touch(float px, float py, t_game *game)
{
    int x;
    int y;

    x = px / game->block;
    y = py / game->block;
    if (game->map[y][x] == '1')
	{
		game->hit_type = 1;
        return (true);
	}
	else if (game->map[y][x] == 'D')
	{
		if (game->open == 0)
		{
			game->hit_type = 2;
			return (true);
		}
	}
	else if (game->map[y][x] == 'C')
	{
		game->hit_type = value_coin(game);
		return (true);
	}
	game->hit_type = 0;
    return (false);
}

float distance(float x, float y)
{
    return sqrt(x * x + y * y);
}

float fixed_dist(float y1, float y2, t_game *game)
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

void draw_line(t_player *player, t_game *game, float start_x, int i)
{
	int	texture_index;
	int	tex_x;
	game->hit_type = 0;

	player->cos_angle = cos(start_x);
	player->sin_angle = sin(start_x);
	player->ray_x = player->x;
	player->ray_y = player->y;
	while (!touch(player->ray_x, player->ray_y, game))
	{
		if (game->DEBUG)
			put_pixel(player->ray_x, player->ray_y, 0xFF0000, game);
		player->ray_x += player->cos_angle;
		player->ray_y += player->sin_angle;
	}
	if (!game->DEBUG)
	{
		if (touch(player->ray_x - player->cos_angle, player->ray_y, game))
		{
			if (game->hit_type == 2)
				texture_index = 4;
			else if (game->hit_type >= 5 && game->hit_type <= 13)
				texture_index = game->hit_type;
			else
				texture_index = (player->ray_y > player->y) ? 0 : 1;
		}
		else
		{
			texture_index = (player->ray_x < player->x) ? 2 : 3;
		}
		game->x1 = player->x;
		game->x2 = player->ray_x;
		game->dist = fixed_dist(player->y, player->ray_y, game);
		game->heightt = (game->block / game->dist) * (game->WIDTH / 2);
		game->start_y = (game->HEIGHT - game->heightt) / 2;
		game->end = game->start_y + game->heightt;
		if (touch(player->ray_x - player->cos_angle, player->ray_y, game))
			tex_x = (int)player->ray_x % game->tex_width;
		else
			tex_x = (int)player->ray_y % game->tex_width;
		render_texture_column(game, texture_index, i, game->start_y, game->end, tex_x);
	}
}
