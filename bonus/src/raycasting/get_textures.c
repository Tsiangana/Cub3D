/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:36 by pzau              #+#    #+#             */
/*   Updated: 2025/02/03 12:31:39 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	init_images(t_game *game)
{
	game->textures[2] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/levels/level1/wall01.xpm",
			&game->tex_width, &game->tex_height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/levels/level1/wall01.xpm",
			&game->tex_width, &game->tex_height);
	game->textures[4] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/levels/level1/door.xpm",
			&game->tex_width, &game->tex_height);
	game->textures[0] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/levels/level1/wall01.xpm", &game->tex_width,
			&game->tex_height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/levels/level1/wall01.xpm",
			&game->tex_width, &game->tex_height);
}

static void	init_coins(t_game *game)
{
	game->textures[5] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin1.xpm", &game->tex_width, &game->tex_height);
	game->textures[6] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin2.xpm", &game->tex_width, &game->tex_height);
	game->textures[7] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin3.xpm", &game->tex_width, &game->tex_height);
	game->textures[8] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin4.xpm", &game->tex_width, &game->tex_height);
	game->textures[9] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin5.xpm", &game->tex_width, &game->tex_height);
	game->textures[10] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin6.xpm", &game->tex_width, &game->tex_height);
	game->textures[11] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin7.xpm", &game->tex_width, &game->tex_height);
	game->textures[12] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin8.xpm", &game->tex_width, &game->tex_height);
	game->textures[13] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/coin/coin9.xpm", &game->tex_width, &game->tex_height);
}

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	init_images(game);
	init_coins(game);
	game->page.life = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/life.xpm", &game->page.life_w, &game->page.life_h);
	while (i < 14)
	{
		if (!game->textures[i] || !game->page.life)
		{
			printf("Error: ao carregar textura \n");
			closelevelone(game);
		}
		game->tex_data[i] = mlx_get_data_addr(game->textures[i],
				&game->tex_bpp[i], &game->tex_sl[i], &game->tex_end[i]);
		i++;
	}
	game->block = game->tex_height;
}

void	render_texture_column(t_game *game, \
	int column, int start_y, int end)
{
	char	*data;
	int		y;
	int		bpp;
	int		sl;

	bpp = game->tex_bpp[game->texture_index];
	sl = game->tex_sl[game->texture_index];
	data = game->tex_data[game->texture_index];
	y = start_y;
	while (y < end)
	{
		game->tex_y = ((y - start_y) * game->tex_height) / (end - start_y);
		if (game->tex_y >= game->tex_height)
			game->tex_y = game->tex_height - 1;
		game->pix_color = *(int *)(data + (game->tex_y * sl + game->tex_x
					* (bpp / 8)));
		game->pix_color = mlx_get_color_value(game->mlxs[0], game->pix_color);
		put_pixel(column, y, game->pix_color, game);
		y++;
	}
}
