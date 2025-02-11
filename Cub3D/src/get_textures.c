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

void load_textures(t_game *game)
{
    char *paths[4] = {
        "textures/one.xpm",
        "textures/two.xpm",
        "textures/three.xpm",
        "textures/four.xpm"
    };

    for (int i = 0; i < 4; i++)
    {
        game->textures[i].img = mlx_xpm_file_to_image(game->mlx, paths[i],
            &game->textures[i].width, &game->textures[i].height);
        
        if (!game->textures[i].img)
        {
            printf("Error: Failed to load texture %s\n", paths[i]);
            exit(1);
        }

        game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
            &game->textures[i].bpp, &game->textures[i].size_line, &game->textures[i].endian);
    }
}

/*---------------------------*/


int get_texture_id(float ray_x, float ray_y, t_game *game)
{
    if (is_vertical_wall(ray_x, ray_y, game))
    {
        return (ray_x > game->player.x) ? 1 : 0;
    }
    else
    {
        return (ray_y > game->player.y) ? 3 : 2;
    }
}

int is_vertical_wall(float x, float y, t_game *game)
{
    int grid_x = (int)x / BLOCK;
    int grid_y = (int)y / BLOCK;

    return (game->map[grid_y][grid_x + 1] == '1' || game->map[grid_y][grid_x - 1] == '1');
}


