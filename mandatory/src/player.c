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

static void	init_player_pos(t_player *player, t_game *game)
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
	player->x = game->WIDTH / 2;
	player->y = game->HEIGHT / 2;
	player->angle = PI / 2;
}

void	init_player(t_player *player, t_game *game)
{
	init_player_pos(player, game);
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == LEFT)
		game->player.left_rotate = true;
	if (keycode == RIGHT)
		game->player.right_rotate = true;
	if (keycode == CLOSE || keycode == CLOSEBTN)
		closewindow(game);
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void	move_player(t_player *player, t_game *game)
{
	float	cos_angle;
	float	sin_angle;
	float	angle_speed;
	float	new_x;
	float	new_y;
	int		speed;

	speed = (int)(game->block / 18);
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);

	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;

	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	new_x = player->x;
	new_y = player->y;
	if (player->key_up)
	{
		new_x += cos_angle * speed;
		new_y += sin_angle * speed;
	}
	if (player->key_down)
	{
		new_x -= cos_angle * speed;
		new_y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		new_x += sin_angle * speed;
		new_y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		new_x -= sin_angle * speed;
		new_y += cos_angle * speed;
	}

	if (!touch(new_x + MARGIN, player->y, game) && !touch(new_x - MARGIN, player->y, game))
		player->x = new_x;
	if (!touch(player->x, new_y + MARGIN, game) && !touch(player->x, new_y - MARGIN, game))
		player->y = new_y;
}
