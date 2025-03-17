/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:33 by pzau              #+#    #+#             */
/*   Updated: 2025/02/27 12:07:35 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static int	ending_page_two(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_image(game->mlxs[0], game->page.page[2]);
	mlx_destroy_window(game->mlxs[0], game->wins[2]);
	mlx_destroy_display(game->mlxs[0]);
	free(game->mlxs[0]);
	exit(0);
	return (0);
}

static void	auto_destroy(t_game *game)
{
	mlx_destroy_image(game->mlxs[0], game->page.page[2]);
	mlx_destroy_window(game->mlxs[0], game->wins[2]);
}

static int	next_page(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65293)
	{
		auto_destroy(game);
		level_one(game);
	}
	return (0);
}

static void	init_image(t_game *game)
{
	game->page.page[2] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/pages/hist/hist_one.xpm",
			&(game->page.width[2]), &(game->page.height[2]));
	if (!game->page.page[2])
	{
		printf("Error: ao carregar imagem hist\n");
		exit(1);
	}
	mlx_put_image_to_window(game->mlxs[0], game->wins[2],
		game->page.page[2], 0, 0);
}

void	page_three(t_game *game)
{
	game->wins[2] = mlx_new_window(game->mlxs[0], 1920, 1080, "Inicio");
	init_image(game);
	put_letters(game);
	mlx_hook(game->wins[2], 17, 0, ending_page_two, game);
	mlx_hook(game->wins[2], 2, 1L << 0, next_page, game);
}
