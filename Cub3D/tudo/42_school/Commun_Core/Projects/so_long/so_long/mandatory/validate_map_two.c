/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:43:37 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 01:45:57 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dfs(char **map, int x, int y, t_game_info *game_info)
{
	if (x < 0 || x >= game_info->dimensoes.width_screen
		|| y < 0 || y >= game_info->dimensoes.height_screen)
		return ;
	if (game_info->state.visited[y][x] || map[y][x] == '1')
		return ;
	game_info->state.visited[y][x] = 1;
	if (map[y][x] == 'C')
		game_info->state.collectables_left--;
	if (map[y][x] == 'E' && game_info->state.collectables_left == 0)
		game_info->state.exit_reachable = 1;
	dfs(map, x - 1, y, game_info);
	dfs(map, x + 1, y, game_info);
	dfs(map, x, y - 1, game_info);
	dfs(map, x, y + 1, game_info);
}
