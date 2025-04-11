/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:33:05 by pzau              #+#    #+#             */
/*   Updated: 2025/03/17 12:33:06 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	init_aux(t_game *game, t_player *player, int y, int x)
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
				init_aux(game, player, y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	player->x = game->widthhy / 2;
	player->y = game->heightty / 2;
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
	if (keycode == ENTER)
		game->open = 1;
	if (keycode == X)
		game->open = 0;
	if (keycode == LEFT)
		game->player.left_rotate = true;
	if (keycode == RIGHT)
		game->player.right_rotate = true;
	if (keycode == CLOSE || keycode == CLOSEBTN)
		closelevelone(game);
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
