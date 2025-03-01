/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:31:11 by pzau              #+#    #+#             */
/*   Updated: 2025/02/22 12:31:14 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int    CloseWindow(t_game *game)
{
    mlx_destroy_image(game->mlxs[0], game->page.page[0]);
    mlx_destroy_image(game->mlxs[0], game->page.buttons[0]);
    mlx_destroy_window(game->mlxs[0], game->wins[0]);
	mlx_destroy_display(game->mlxs[0]);
    free(game->mlxs[0]);
    exit(0);
    return (0);
}

int    Closet(t_game *game)
{
    mlx_destroy_window(game->mlxs[0], game->wins[0]);
	mlx_destroy_display(game->mlxs[0]);
    free(game->mlxs[0]);
    exit(0);
    return (0);
}
