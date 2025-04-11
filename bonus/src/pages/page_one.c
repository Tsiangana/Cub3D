/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:26:43 by pzau              #+#    #+#             */
/*   Updated: 2025/02/22 13:26:44 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	ending(t_game *game)
{
	mlx_destroy_image(game->mlxs[0], game->page.page[0]);
	mlx_destroy_image(game->mlxs[0], game->page.buttons[0]);
	mlx_destroy_window(game->mlxs[0], game->wins[0]);
}

void	start_page_one(t_game *game, t_pages *pages)
{
	int	x_pos;
	int	y_pos;

	pages->page[0] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/pages/intro.xpm", &(pages->width[0]), &(pages->height[0]));
	pages->buttons[0] = mlx_xpm_file_to_image(game->mlxs[0],
			"assets/buttons/button_start.xpm", &(pages->w_button[0]),
			&(pages->h_button[0]));
	if (!pages->page[0] || !pages->buttons[0])
	{
		printf("Error ao carregar imagem\n");
		closet(game);
	}
	x_pos = (pages->width[0] - pages->w_button[0]) / 2;
	y_pos = (pages->height[0] - pages->h_button[0]) / 1.2;
	mlx_put_image_to_window(game->mlxs[0], game->wins[0], pages->page[0], 0, 0);
	mlx_put_image_to_window(game->mlxs[0], game->wins[0],
		pages->buttons[0], x_pos, y_pos);
}

int	start_button(int button, int x, int y, t_game *game)
{
	if (button == 1)
	{
		if (x >= 471 && x <= 531 && y >= 450 && y <= 469)
		{
			ending(game);
			start_page_two(game);
		}
	}
	return (0);
}
