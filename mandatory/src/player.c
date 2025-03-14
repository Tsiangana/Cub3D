/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:05:44 by pzau              #+#    #+#             */
/*   Updated: 2025/01/24 13:05:46 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	aux_init_player(t_player *player, t_game *game, int y, int x)
{
	player->x = x * game->block + game->block / 2;
	player->y = y * game->block + game->block / 2;
	if (game->map[y][x] == 'N')
		player->angle = 3 * PI / 2;
	else if (game->map[y][x] == 'S')
		player->angle = PI / 2;
	else if (game->map[y][x] == 'E')
		player->angle = 0;
	else if (game->map[y][x] == 'W')
		player->angle = PI;
	game->map[y][x] = '0';
}

void	init_player_pos(t_player *player, t_game *game)
{
	char	c;
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			c = game->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				aux_init_player(player, game, y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	player->x = game->widthyy / 2;
	player->y = game->heightyy / 2;
	player->angle = PI / 2;
}

static void	aux_move_player(t_player *player, t_game *game)
{
	if (player->key_up)
	{
		game->new_x += game->cos_angle * game->speed;
		game->new_y += game->sin_angle * game->speed;
	}
	if (player->key_down)
	{
		game->new_x -= game->cos_angle * game->speed;
		game->new_y -= game->sin_angle * game->speed;
	}
	if (player->key_left)
	{
		game->new_x += game->sin_angle * game->speed;
		game->new_y -= game->cos_angle * game->speed;
	}
	if (player->key_right)
	{
		game->new_x -= game->sin_angle * game->speed;
		game->new_y += game->cos_angle * game->speed;
	}
}

void	move_player(t_player *player, t_game *game)
{
	game->speed = (int)(game->block / 18);
	game->angle_speed = 0.03;
	game->cos_angle = cos(player->angle);
	game->sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= game->angle_speed;
	if (player->right_rotate)
		player->angle += game->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	game->new_x = player->x;
	game->new_y = player->y;
	aux_move_player(player, game);
	if (!touch(game->new_x + MARGIN, player->y, game)
		&& !touch(game->new_x - MARGIN, player->y, game))
		player->x = game->new_x;
	if (!touch(player->x, game->new_y + MARGIN, game)
		&& !touch(player->x, game->new_y - MARGIN, game))
		player->y = game->new_y;
}
