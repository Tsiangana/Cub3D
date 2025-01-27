/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:05:37 by pzau              #+#    #+#             */
/*   Updated: 2025/01/24 13:05:39 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void    init_game(t_game *game, char *str)
{
    init_player(&game->player);
    game->map = get_map(str);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int main(int ac, char **av)
{
    t_game  game;

    if (ac == 2)
    {
        init_game(&game, av[1]);

        mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
        mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);

        mlx_loop_hook(game.mlx, draw_loop, &game);
        mlx_loop(game.mlx);
    }
    else
        printf("error\nIncorrect Arguments");
    return (0);
}
