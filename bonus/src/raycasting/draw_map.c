/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:07:34 by pzau              #+#    #+#             */
/*   Updated: 2025/01/24 13:07:35 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= game->WIDTH || y >= game->HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int x, int y, int size, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
		put_pixel(x + i++, y, game->color, game);
	i = 0;
	while (i < size)
		put_pixel(x, y + i++, game->color, game);
	i = 0;
	while (i < size)
		put_pixel(x + size, y + i++, game->color, game);
	i = 0;
	while (i < size)
		put_pixel(x + i++, y + size, game->color, game);
}

void	draw_map(t_game *game)
{
	char	**map;
	int		color;
	int		y;
	int		x;

	map = game->map;
	color = 0xFFFF00;
	game->size = game->block;
	show_grid(game, '0', 0xE0FFFF);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				show_square(x * game->block, y * game->block,
					color, game);
			x++;
		}
		y++;
	}
	show_grid(game, '1', 0xE0FFFF);
}

static	void	aux_draw_loop(t_game *game, t_player *player)
{
	game->color = 0x00FF00;
	move_player(player, game);
	clear_image(game);
	draw_background(game);
	if (game->DEBUG)
	{
		draw_square(player->x, player->y, 10, game);
		draw_map(game);
	}
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	player = &game->player;
	aux_draw_loop(game, player);
	start_x = player->angle - PI / 6;
	fraction = PI / 3 / game->WIDTH;
	i = 0;
	while (i < game->WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->img, 0, 0);
	showing_lives(game);
	draw_minimap(game);
	return (0);
}
