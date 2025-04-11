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

int	main(void)
{
	t_game	game;

	game.mlxs[0] = mlx_init();
	game.wins[0] = mlx_new_window(game.mlxs[0], 1000, 562,
			"Ori and the Blind Florest");
	start_page_one(&game, &game.page);
	mlx_mouse_hook(game.wins[0], start_button, &game);
	mlx_hook(game.wins[0], 17, 0, closewindow, &game);
	mlx_loop(game.mlxs[0]);
	return (0);
}
