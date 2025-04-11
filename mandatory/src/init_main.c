/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:39:04 by lmachado          #+#    #+#             */
/*   Updated: 2025/04/10 14:37:20 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	initialize_game(t_game *game)
{
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->map = NULL;
	game->lines = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->tab.y = 0;
	game->tab.x = 0;
	game->tab.new_line = NULL;
	game->tab.tab_count = 0;
	game->tab.new_len = 0;
	game->tab.k = 0;
}

void	free_all(t_game *game)
{
	if (game->no_texture)
		free(game->no_texture);
	if (game->so_texture)
		free(game->so_texture);
	if (game->we_texture)
		free(game->we_texture);
	if (game->ea_texture)
		free(game->ea_texture);
	free_split(game->lines);
	free_split(game->map);
}
