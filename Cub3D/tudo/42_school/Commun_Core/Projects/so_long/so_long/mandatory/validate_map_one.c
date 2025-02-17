/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:34 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 01:45:25 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_visited_and_collectables(t_game_info *game_info, char **map)
{
	int	x;
	int	y;

	game_info->state.visited = (int **)malloc(sizeof(int *)
			* game_info->dimensoes.height_screen);
	y = 0;
	while (y < game_info->dimensoes.height_screen)
	{
		game_info->state.visited[y] = (int *)malloc(sizeof(int)
				* game_info->dimensoes.width_screen);
		x = 0;
		while (x < game_info->dimensoes.width_screen)
		{
			game_info->state.visited[y][x] = 0;
			if (map[y][x] == 'C')
				game_info->state.collectables_left++;
			x++;
		}
		y++;
	}
}

void	free_visited(t_game_info *game_info)
{
	int	y;

	y = 0;
	while (y < game_info->dimensoes.height_screen)
	{
		free(game_info->state.visited[y]);
		y++;
	}
	free(game_info->state.visited);
}

int	find_player_position(char **map, t_game_info *game_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < game_info->dimensoes.height_screen)
	{
		x = 0;
		while (x < game_info->dimensoes.width_screen)
		{
			if (map[y][x] == 'P')
			{
				dfs(map, x, y, game_info);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	verify_playability(t_game_info *game_info, t_vars *vars)
{
	if (game_info->state.collectables_left > 0
		|| !game_info->state.exit_reachable)
	{
		ft_printf("  Mapa inválido: itens inacessíveis\n\n");
		free_split(vars->map);
		free_visited(game_info);
		exit(1);
	}
}

void	check_map_playability(char **map, t_vars *vars)
{
	t_game_info	game_info;

	game_info.state.collectables_left = 0;
	game_info.state.exit_reachable = 0;
	game_info.dimensoes = vars->dim;
	init_visited_and_collectables(&game_info, map);
	if (!find_player_position(map, &game_info))
	{
		ft_printf("  Mapa inválido: jogador não encontrado\n\n");
		free_visited(&game_info);
		exit(1);
	}
	verify_playability(&game_info, vars);
	free_visited(&game_info);
}
