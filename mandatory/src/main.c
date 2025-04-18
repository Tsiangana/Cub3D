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

static void	init_images(t_game *game)
{
	game->textures[0] = NULL;
	game->textures[1] = NULL;
	game->textures[2] = NULL;
	game->textures[3] = NULL;
}

void	init_game(t_game *game, char *str)
{
	game->debug = 0;
	open_get_size(str, game);
	responsivo(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->widthyy,
			game->heightyy, "Game");
	init_images(game);
	load_textures(game);
	mlx_hook(game->win, 17, 0, closewindow, game);
	init_player(&game->player, game);
	game->img = mlx_new_image(game->mlx, game->widthyy, game->heightyy);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		check_arguments(ac, av, &game);
		initialize_game(&game);
		game.lines = print_map(av[1]);
		parse_game(&game, game.lines);
		validate_all(&game);
		init_game(&game, av[1]);
		mlx_hook(game.win, 2, 1L << 0, key_press, &game);
		mlx_hook(game.win, 3, 1L << 1, key_release, &game.player);
		mlx_loop_hook(game.mlx, draw_loop, &game);
		mlx_loop(game.mlx);
	}
	else
		printf("error\nIncorrect Arguments");
	return (0);
}
