/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:43:50 by lmachado          #+#    #+#             */
/*   Updated: 2025/04/11 10:46:55 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	add_tab(t_game *game)
{
	int	i;

	i = 0;
	game->tab.j = 0;
	while (game->map[game->tab.y] != NULL)
	{
		game->tab.tab_count = 0;
		game->tab.x = 0;
		while (game->map[game->tab.y][game->tab.x])
		{
			if (game->map[game->tab.y][game->tab.x] == '\t')
				game->tab.tab_count++;
			game->tab.x++;
		}
		game->tab.new_len = game->tab.x + game->tab.tab_count * (TAB_WIDTH - 1);
		game->tab.new_line = malloc(game->tab.new_len + 1);
		if (!game->tab.new_line)
			return ;
		aux_add_tab(game);
		game->tab.new_line[game->tab.j] = '\0';
		free(game->map[game->tab.y]);
		game->map[game->tab.y] = game->tab.new_line;
		game->tab.y++;
	}
}

void	add_space(t_game *game)
{
	char	*new_line;
	int		x;
	int		y;

	if (!game || !game->map)
		return ;
	y = 0;
	new_line = NULL;
	while (game->map[y] != NULL)
	{
		x = strlen(game->map[y]);
		new_line = malloc((x + 2) * sizeof(char));
		if (!new_line)
			return ;
		strcpy(new_line, game->map[y]);
		new_line[x] = ' ';
		new_line[x + 1] = '\0';
		free(game->map[y]);
		game->map[y] = new_line;
		y++;
	}
	add_tab(game);
}

void	change_one_at_space(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == ' ')
				game->map[y][x] = '1';
			x++;
		}
		y++;
	}
}

static void	aux_validate_all(t_game *game)
{
	if (verify_extension(game->no_texture) || verify_extension(game->so_texture)
		|| verify_extension(game->we_texture)
		|| verify_extension(game->ea_texture))
	{
		printf("Error: Chave invalida\n");
		free_all(game);
		exit(0);
	}
	if (is_valid_color(game->ceiling_color)
		|| is_valid_color(game->floor_color))
	{
		printf("Error: cor invalida\n");
		free_all(game);
		exit(0);
	}
}

void	validate_all(t_game *game)
{
	if (verify_characters(game))
	{
		printf("Error: Mapa invalido\n");
		free_all(game);
		exit(0);
	}
	add_space(game);
	aux_validate_all(game);
	if (verify_space(game))
	{
		printf("Error: Mapa invalido\n");
		free_all(game);
		exit(0);
	}
	else
	{
		game->color_c = get_color(game->ceiling_color);
		game->color_f = get_color(game->floor_color);
	}
	change_one_at_space(game);
}
