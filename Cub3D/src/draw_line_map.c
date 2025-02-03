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
        if (dist <= 0) dist = 0.0001;  // Garante que dist nunca seja zero

        float height = (BLOCK / dist) * (game->WIDTH / 2);
        if (height < 1) height = 1;  // Garante altura válida

        int start_y = (game->HEIGHT - height) / 2;
        int end = start_y + height;

        int texture_id = get_wall_texture(cos_angle, sin_angle);
        if (texture_id < 0 || texture_id >= 4) {
            printf("Erro: ID de textura inválido: %d\n", texture_id);
            return;
        }

        t_texture *texture = &game->textures[texture_id];

        int texture_x = (int)(ray_x * texture->width) % texture->width;
        if (texture_x < 0) texture_x = 0;
        if (texture_x >= texture->width) texture_x = texture->width - 1;

        for (int y = start_y; y < end; y++)
        {
            int texture_y = 1;  // Valor seguro
            if (height > 0)  // Garante que a divisão seja segura
                texture_y = ((y - start_y) * texture->height) / height;

            if (texture_y < 0) texture_y = 0;
            if (texture_y >= texture->height)
                texture_y = texture->height - 1;

            int color = get_textures_color(texture, texture_x, texture_y);
            put_pixel(i, y, color, game);
        }
    }
}


/*void draw_line(t_player *player, t_game *game, float start_x, int i)
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
        float height = (BLOCK / dist) * (game->WIDTH / 2);
        int start_y = (game->HEIGHT - height) / 2;
        int end = start_y + height;

        while (start_y < end)
        {
            put_pixel(i, start_y, 0x0FFF00, game);
            start_y++;
        }
    }
}*/
