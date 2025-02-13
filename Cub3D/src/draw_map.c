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

#include "../includes/game.h"

void    put_pixel(int x, int y, int color, t_game *game)
{
    if (x >= game->WIDTH || y >= game->HEIGHT || x < 0 || y < 0)
        return ;
    int index = y * game->size_line + x * game->bpp / 8;
    game->data[index] = color & 0xFF;
    game->data[index + 1] = (color >> 8) & 0xFF;
    game->data[index + 2] = (color >> 16) & 0xFF;
}

void    draw_square(int x, int y, int size, int color, t_game *game)
{
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y, color, game);
    for (int i = 0; i < size; i++)
        put_pixel(x, y + i, color, game);
    for (int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, game);
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, game);
}

void    draw_map(t_game *game)
{
    char **map = game->map;
    int color = 0xFFFF00;
    show_grid(game, '0', 0xE0FFFF);
    for (int y = 0; map[y]; y++)
    {
        for(int x = 0; map[y][x]; x++)
        {
            if (map[y][x] == '1')
                show_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
        }
    }
    show_grid(game, '1', 0xE0FFFF);
}

void    clear_image(t_game *game)
{
    for (int y = 0; y < game->HEIGHT; y++)
        for (int x = 0; x < game->WIDTH; x++)
            put_pixel(x, y, 0, game);
}

void    draw_background(t_game *game)
{
    int x;
    int y;
    int sky_color = 0x87CEEB;
    int floor_color = 0x8B4513;

    for (y = 0; y < game->HEIGHT / 2; y++)
    {
        for (x = 0; x < game->WIDTH; x++)
            put_pixel(x, y, sky_color, game);
    }
    for (y = game->HEIGHT / 2; y < game->HEIGHT; y++)
    {
        for (x = 0; x  < game->WIDTH; x++)
            put_pixel(x, y, floor_color, game);
    }
}

int draw_loop(t_game *game)
{
    t_player *player = &game->player;
    move_player(player, game);
    clear_image(game);
    draw_background(game);

    if (game->DEBUG)
    {
        draw_square(player->x, player->y, 10, 0x00FF00, game);
        draw_map(game);
    }

    float fraction = PI / 3 / game->WIDTH;
    float start_x = player->angle - PI / 6;
    int i = 0;

    while (i < game->WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }

    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
