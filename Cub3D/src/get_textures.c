/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:31:36 by pzau              #+#    #+#             */
/*   Updated: 2025/02/03 12:31:39 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"\

void    load_textures(t_game *game)
{
    char    *texture_paths[4] = {
        "../textures/one.xpm",
        "../textures/two.xpm",
        "../textures/three.xpm",
        "../textures/four.xpm"
    };

    for (int i = 0; i < 4; i++)
    {
        game->textures[i].img = mlx_xpm_file_to_image(game->mlx, texture_paths[i], &game->textures[i].width, &game->textures[i].height);
        if (!game->textures[i].img)
        {
            printf("error\nerro ao carregar imagens: %s\n", texture_paths[i]);
            exit(EXIT_FAILURE);
        }
        game->textures[i].addr = mlx_get_data_addr(game->textures[i].img, &game->textures[i].bpp, &game->textures[i].line_length, &game->textures[i].endian);
    }
}

int get_textures_color(t_texture *texture, int x, int y)
{
    char *pixel;
    int color;

    if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
        return (0);
    pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
    color = *(unsigned int *)pixel;
    return (color);
}

int get_wall_texture(float step_x, float step_y)
{
    if (fabs(step_x) > fabs(step_y))
        return (step_x > 0) ? 2 : 3;
    else
        return (step_y > 0) ? 1 : 0;
}
