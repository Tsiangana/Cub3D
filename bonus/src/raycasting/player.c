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

#include "../../includes/game.h"

static void	aux_move_player(t_player *player, t_game *game)
{
	game->player.speed = (int)(game->block / 18);
	game->player.angle_speed = 0.03;
	game->player.cos_angle = cos(player->angle);
	game->player.sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= game->player.angle_speed;
	if (player->right_rotate)
		player->angle += game->player.angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	game->player.new_x = player->x;
	game->player.new_y = player->y;
}

static void	aux_two(t_player *player, t_game *game)
{
	if (!touch_aux(game->player.new_x + MARGIN, player->y, game)
		&& !touch(game->player.new_x - MARGIN, player->y, game))
		player->x = game->player.new_x;
	if (!touch_aux(player->x, game->player.new_y + MARGIN, game)
		&& !touch(player->x, game->player.new_y - MARGIN, game))
		player->y = game->player.new_y;
}

void	move_player(t_player *player, t_game *game)
{
	aux_move_player(player, game);
	if (player->key_up)
	{
		game->player.new_x += game->player.cos_angle * game->player.speed;
		game->player.new_y += game->player.sin_angle * game->player.speed;
	}
	if (player->key_down)
	{
		game->player.new_x -= game->player.cos_angle * game->player.speed;
		game->player.new_y -= game->player.sin_angle * game->player.speed;
	}
	if (player->key_left)
	{
		game->player.new_x += game->player.sin_angle * game->player.speed;
		game->player.new_y -= game->player.cos_angle * game->player.speed;
	}
	if (player->key_right)
	{
		game->player.new_x -= game->player.sin_angle * game->player.speed;
		game->player.new_y += game->player.cos_angle * game->player.speed;
	}
	aux_two(player, game);
}
