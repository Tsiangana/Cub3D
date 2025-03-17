/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_three_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:52:35 by pzau              #+#    #+#             */
/*   Updated: 2025/03/14 11:52:36 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	draw_large_text(void *mlx, void *win, \
	int x, int y, int color, char *text)
{
	mlx_string_put(mlx, win, x, y, color, text);
	mlx_string_put(mlx, win, x + 1, y, color, text);
	mlx_string_put(mlx, win, x, y + 1, color, text);
	mlx_string_put(mlx, win, x + 1, y + 1, color, text);
}

void	put_letters(t_game *game)
{
	mlx_string_put(game->mlxs[0], game->wins[2], 600, 230, 0xFFFFFF,
		"Espero que voces gostem dele.");
	mlx_string_put(game->mlxs[0], game->wins[2], 600, 260, 0xFFFFFF,
		"A gente colocou uma dinamica de jogabilidade diferente");
	mlx_string_put(game->mlxs[0], game->wins[2], 600, 290, 0xFFFFFF,
		"E esperamos que isso seje do seu agrado");
	mlx_string_put(game->mlxs[0], game->wins[2], 600, 320, 0xFFFFFF,
		"Explore os niveis, derote os inimigos, e partilhe com seus amigos");
	mlx_string_put(game->mlxs[0], game->wins[2], 600, 350, 0xFFFFFF,
		"Boa sorte e divirta-se");
	mlx_string_put(game->mlxs[0], game->wins[2], 600, 200, 0xFFFFFF,
		"Bem-vindos ao Jogo do Amazing team");
	draw_large_text(game->mlxs[0], game->wins[2], 600, 400, 0xFFFFFF,
		"Precione ENTER para iniciar");
}
