/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:30:46 by pzau              #+#    #+#             */
/*   Updated: 2025/02/03 11:30:49 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	closewindow(t_game *game)
{
	int	i;
	int	on;

	i = 0;
	on = 0;
	free_split(game->map);
	while (i < 4)
	{
		if (game->textures[i])
		{
			mlx_destroy_image(game->mlx, game->textures[i]);
			game->textures[i] = NULL;
			on++;
		}
		i++;
	}
	if (on == 4)
		mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
