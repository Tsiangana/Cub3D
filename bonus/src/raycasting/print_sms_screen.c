/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sms_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:02:02 by pzau              #+#    #+#             */
/*   Updated: 2025/03/14 15:02:03 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	sms_one(t_game *game)
{
	if (game->coins >= 3)
	{
		mlx_string_put(game->mlxs[0], game->wins[3], 20, 20,
			0xFFFFFF, "coins: 3+");
		mlx_put_image_to_window(game->mlxs[0], game->wins[3],
			game->page.life, 20, 30);
		mlx_put_image_to_window(game->mlxs[0], game->wins[3],
			game->page.life, 50, 30);
		mlx_put_image_to_window(game->mlxs[0], game->wins[3],
			game->page.life, 80, 30);
	}
}

static void	sms_two(t_game *game)
{
	if (game->coins == 2)
	{
		mlx_string_put(game->mlxs[0], game->wins[3], 20, 20,
			0xFFFFFF, "coins: 2");
		mlx_put_image_to_window(game->mlxs[0], game->wins[3],
			game->page.life, 20, 30);
		mlx_put_image_to_window(game->mlxs[0], game->wins[3],
			game->page.life, 50, 30);
	}
}

static void	sms_three(t_game *game)
{
	if (game->coins == 1)
	{
		mlx_string_put(game->mlxs[0], game->wins[3], 20, 20,
			0xFFFFFF, "coins: 1");
		mlx_put_image_to_window(game->mlxs[0], game->wins[3],
			game->page.life, 20, 30);
	}
}

void	showing_lives(t_game *game)
{
	sms_one(game);
	sms_two(game);
	sms_three(game);
	mlx_string_put(game->mlxs[0], game->wins[3], 870, 20,
		0xFFFFFF, "Find the coin to Win the Game !");
	mlx_string_put(game->mlxs[0], game->wins[3], 1700, 960, 0xFFFFFF,
		"Use X to close the door !");
	mlx_string_put(game->mlxs[0], game->wins[3], 1700, 980, 0xFFFFFF,
		"Use ENTER to open the door");
	return ;
}
