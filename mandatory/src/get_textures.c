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

#include "../includes/game.h"

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, game->no_texture,
			&game->tex_width, &game->tex_height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, game->so_texture,
			&game->tex_width, &game->tex_height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, game->we_texture,
			&game->tex_width, &game->tex_height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx, game->ea_texture,
			&game->tex_width, &game->tex_height);
	while (i < 4)
	{
		if (!game->textures[i])
		{
			printf("error: ao carregar textura %d\n", i);
			closewindow(game);
		}
		game->tex_data[i] = mlx_get_data_addr(game->textures[i],
				&game->tex_bpp[i], &game->tex_sl[i], &game->tex_end[i]);
		i++;
	}
	game->block = game->tex_height;
}

void	render_texture_column(t_game *game, int start_y, int end, int tex_x)
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
		game->pix_color = *(int *)(data + (game->tex_y
					* sl + tex_x * (bpp / 8)));
		game->pix_color = mlx_get_color_value(game->mlx, game->pix_color);
		put_pixel(game->column, y, game->pix_color, game);
		y++;
	}
}
