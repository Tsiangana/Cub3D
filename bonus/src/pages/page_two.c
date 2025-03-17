/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:26:51 by pzau              #+#    #+#             */
/*   Updated: 2025/02/24 12:26:52 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static int	ending_page_two(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_image(game->mlxs[0], game->page.page[1]);
	mlx_destroy_window(game->mlxs[0], game->wins[1]);
	mlx_destroy_display(game->mlxs[0]);
	free(game->mlxs[0]);
	exit(0);
	return (0);
}

static void	auto_destroy(t_game *game)
{
	mlx_destroy_image(game->mlxs[0], game->page.page[1]);
	mlx_destroy_window(game->mlxs[0], game->wins[1]);
}

static int	next_page(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 97)
	{
		auto_destroy(game);
		page_three(game);
	}
	return (0);
}

static void	init_image(t_game *game, t_pages *pages)
{
	pages->page[1] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/pages/first_page.xpm",
			&(pages->width[0]), &(pages->height[0]));
	if (!pages->page[1])
	{
		printf("erro ao abrir imagem\n");
		ending_page_two(game);
	}
	mlx_put_image_to_window(game->mlxs[0], game->wins[1], pages->page[1], 0, 0);
}

void	start_page_two(t_game *game)
{
	game->wins[1] = mlx_new_window(game->mlxs[0], 1920, 1080, "Start Page");
	init_image(game, &game->page);
	mlx_hook(game->wins[1], 17, 0, ending_page_two, game);
	mlx_hook(game->wins[1], 2, 1L << 0, next_page, game);
}
