/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:26:03 by pzau              #+#    #+#             */
/*   Updated: 2025/01/27 10:26:04 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void    show_grid(t_game *game, char value, int color)
{
    char **map = game->map;
    for (int y = 0; map[y]; y++)
        for(int x = 0; map[y][x]; x++)
            if (map[y][x] == value)
                draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
}

void    show_square(int x, int y, int size, int color, t_game *game)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            put_pixel(x + j, y + i, color, game);
    }
}
