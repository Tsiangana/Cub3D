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

#include "../../includes/game.h"

void    put_pixel(int x, int y, int color, t_game *game)
{
    int index;

    if (x >= game->WIDTH || y >= game->HEIGHT || x < 0 || y < 0)
        return ;
    index = y * game->size_line + x * game->bpp / 8;
    game->data[index] = color & 0xFF;
    game->data[index + 1] = (color >> 8) & 0xFF;
    game->data[index + 2] = (color >> 16) & 0xFF;
}

void    draw_square(int x, int y, int size, int color, t_game *game)
{
    int i;

    i = 0;
    while (i < size)
        put_pixel(x + i++, y, color, game);
    i = 0;
    while (i < size)
        put_pixel(x, y + i++, color, game);
    i = 0;
    while (i < size)
        put_pixel(x + size, y + i++, color, game);
    i = 0;
    while (i < size)
        put_pixel(x + i++, y + size, color, game);
}


void    draw_map(t_game *game)
{
    char **map;
    int color;
    int y;
    int x;

    map = game->map;
    color = 0xFFFF00;
    show_grid(game, '0', 0xE0FFFF);
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                show_square(x * game->block, y * game->block, game->block, color, game);
            x++;
        }
        y++;
    }
    show_grid(game, '1', 0xE0FFFF);
}

void    clear_image(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->HEIGHT)
    {
        x = 0;
        while (x < game->WIDTH)
        {
            put_pixel(x, y, 0, game);
            x++;
        }
        y++;
    }
}

void draw_background(t_game *game)
{
    int sky_color;
    int floor_color;
    int y;
    int x;

    sky_color = 0x000000;
    floor_color = 0x000000;
    y = 0;
    while (y < game->HEIGHT / 2)
    {
        x = 0;
        while (x < game->WIDTH)
        {
            put_pixel(x, y, sky_color, game);
            put_pixel(x, game->HEIGHT - y - 1, floor_color, game);
            x++;
        }
        y++;
    }
}

static void showing_lives(t_game *game)
{
    if (game->live == 3)
    {
        mlx_string_put(game->mlxs[0], game->wins[3], 10, 10, 0xFFFFFF,"Vidas: 3");
        mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->page.life, 20, 10);
        mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->page.life, 80, 10);
        mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->page.life, 140, 10);
    }
    else if (game->live == 2)
    {
        mlx_string_put(game->mlxs[0], game->wins[3], 10, 10, 0xFFFFFF,"Vidas: 2");
        mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->page.life, 20, 10);
        mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->page.life, 80, 10);
    }
    else if (game->live == 1)
    {
        mlx_string_put(game->mlxs[0], game->wins[3], 10, 10, 0xFFFFFF,"Vidas: 1");
        mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->page.life, 20, 10);
    }
    else
    {
        mlx_string_put(game->mlxs[0], game->wins[3], 10, 10, 0xFFFFFF,"You Lose");
    }
    mlx_string_put(game->mlxs[0], game->wins[3], 870, 20, 0xFFFFFF,"Find the coin to Win the Game !");
    return ;
}

static void draw_minimap(t_game *game)
{
    int x, y;
    int block_size = game->block * MINIMAP_SCALE;
    int minimap_size = 6; // Define quantos blocos ao redor do jogador serão exibidos

    int player_map_x = game->player.x / game->block;
    int player_map_y = game->player.y / game->block;

    int minimap_x = game->WIDTH - (minimap_size * block_size) - 20; // Canto superior direito
    int minimap_y = 20;

    for (y = -minimap_size / 2; y < minimap_size / 2; y++)
    {
        for (x = -minimap_size / 2; x < minimap_size / 2; x++)
        {
            int map_x = player_map_x + x;
            int map_y = player_map_y + y;

            if (map_x >= 0 && map_y >= 0 && game->map[map_y] && game->map[map_y][map_x])
            {
                if (game->map[map_y][map_x] == '1')
                    show_square(minimap_x + (x + minimap_size / 2) * block_size, minimap_y + (y + minimap_size / 2) * block_size, block_size, 0xFFFFFF, game);
                else
                    show_square(minimap_x + (x + minimap_size / 2) * block_size, minimap_y + (y + minimap_size / 2) * block_size, block_size,  0x1388ef , game);
            }
        }
    }

    // Desenha o jogador no minimapa (sempre no centro da área visível)
    int player_x = minimap_x + (minimap_size / 2) * block_size;
    int player_y = minimap_y + (minimap_size / 2) * block_size;
    draw_square(player_x - 2, player_y - 2, 5, 0xFF0000, game); // Vermelho para o jogador
}



int draw_loop(t_game *game)
{
    float fraction;
    float start_x;
    t_player *player;
    int i;

    player = &game->player;
    move_player(player, game);
    clear_image(game);
    draw_background(game);
    if (game->DEBUG)
    {
        draw_square(player->x, player->y, 10, 0x00FF00, game);
        draw_map(game);
    }
    start_x = player->angle - PI / 6;
    fraction = PI / 3 / game->WIDTH;
    i = 0;
    while (i < game->WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->img, 0, 0);
    showing_lives(game);
    draw_minimap(game);
    return (0);
}
