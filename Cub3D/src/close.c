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

int    CloseWindow(t_game *game)
{
    free_split(game->map);
    mlx_destroy_image(game->mlx, game->img);
    mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
    return (0);
}
