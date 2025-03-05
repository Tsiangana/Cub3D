/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:37:18 by pzau              #+#    #+#             */
/*   Updated: 2025/02/27 14:37:19 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int    CloseLevelOne(t_game *game)
{
    int i;
    int on;

    i = 0;
    on = 0;
    free_split(game->map);
    while (i < 4)
    {
        if (game->textures[i])
        {
            mlx_destroy_image(game->mlxs[0], game->textures[i]);
            game->textures[i] = NULL;
            on++;
        }
        i++;
    }
    if (on == 4)
        mlx_destroy_image(game->mlxs[0], game->img);
    mlx_destroy_window(game->mlxs[0], game->wins[3]);
	mlx_destroy_display(game->mlxs[0]);
    free(game->mlxs[0]);
    exit(0);
    return (0);
}

void init_game(t_game *game, char *str)
{
    game->DEBUG = 0;
    game->live = 3;
    game->map = get_map(str);
    open_get_size(str, game);
    responsivo(game);
    game->wins[3] = mlx_new_window(game->mlxs[0], game->WIDTH, game->HEIGHT, "Ori - Level one");
    load_textures(game);
    mlx_hook(game->wins[3], 17, 0, CloseLevelOne, game);
    init_player(&game->player, game);
    game->img = mlx_new_image(game->mlxs[0], game->WIDTH, game->HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlxs[0], game->wins[3], game->img, 0, 0);
}

void level_one(t_game *game)
{
    init_game(game, "maps/level1/one.cub");

    mlx_hook(game->wins[3], 2, 1L << 0, key_press, game);
    mlx_hook(game->wins[3], 3, 1L << 1, key_release, &game->player);

    mlx_loop_hook(game->mlxs[0], draw_loop, game);
}
