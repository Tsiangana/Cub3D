/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:18:01 by pzau              #+#    #+#             */
/*   Updated: 2025/01/25 12:18:02 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

bool    touch(float px, float py, t_game *game)
{
    int x = px / BLOCK;
    int y = py / BLOCK;
    if (game->map[y][x] == '1')
        return (true);
    return (false);    
}

float distance(float x, float y)
{
    return sqrt(x * x + y * y);    
}

float fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float angle = atan2(delta_y, delta_x) - game->player.angle;
    float fix_dist  = distance(delta_x, delta_y) * cos(angle);
    return (fix_dist);
}

void draw_line(t_player *player, t_game *game, float start_x, int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float ray_x = player->x;
    float ray_y = player->y;

    while (!touch(ray_x, ray_y, game))
    {
        if (game->DEBUG)
            put_pixel(ray_x, ray_y, 0x7FFFD4, game);
        ray_x += cos_angle;
        ray_y += sin_angle;
    }

    if (!game->DEBUG)
    {
        float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
        float height = (BLOCK * game->HEIGHT) / (dist * 2);

        int start_y = fmax(0, (game->HEIGHT - height) / 2);
        int end_y = fmin(game->HEIGHT - 1, start_y + height);

        int texture_id = get_texture_id(ray_x, ray_y, game);
        t_texture *tex = &game->textures[texture_id];

        float wall_x = ray_x - floor(ray_x);
        int tex_x = (int)(wall_x * tex->width);

        for (int y = start_y; y < end_y; y++)
        {
            int tex_y = (int)((y - start_y) * tex->height / height);
            int color = *(int *)(tex->addr + (tex_y * tex->size_line + tex_x * (tex->bpp / 8)));

            put_pixel(i, y, color, game);
        }
    }
}
