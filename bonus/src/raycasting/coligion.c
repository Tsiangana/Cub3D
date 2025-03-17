/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coligion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:23:53 by pzau              #+#    #+#             */
/*   Updated: 2025/03/17 12:23:55 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	aux_one(t_game *game, float px, float py)
{
	game->colig_x = px / game->block;
	game->colig_y = py / game->block;
	if (game->coins == 0)
	{
		youwin();
		CloseLevelOne(game);
	}
}

bool	touch_aux(float px, float py, t_game *game)
{
	aux_one(game, px, py);
	if (game->map[game->colig_y][game->colig_x] == '1')
	{
		game->hit_type = 1;
		return (true);
	}
	else if (game->map[game->colig_y][game->colig_x] == 'D')
	{
		if (game->open == 0)
		{
			game->hit_type = 2;
			return (true);
		}
	}
	else if (game->map[game->colig_y][game->colig_x] == 'C')
	{
		game->map[game->colig_y][game->colig_x] = '0';
		game->coins--;
		game->hit_type = 3;
		return (false);
	}
	game->hit_type = 0;
	return (false);
}
