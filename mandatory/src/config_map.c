/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:02:34 by lmachado          #+#    #+#             */
/*   Updated: 2025/04/11 10:43:36 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	parse_line(t_game *game, char *line)
{
	while (*line == ' ')
		line++;
	if (strncmp(line, "NO ", 3) == 0)
		game->no_texture = strdup(line + 3);
	else if (strncmp(line, "SO ", 3) == 0)
		game->so_texture = strdup(line + 3);
	else if (strncmp(line, "WE ", 3) == 0)
		game->we_texture = strdup(line + 3);
	else if (strncmp(line, "EA ", 3) == 0)
		game->ea_texture = strdup(line + 3);
	else if (strncmp(line, "F ", 2) == 0)
		game->floor_color = line + 2;
	else if (strncmp(line, "C ", 2) == 0)
		game->ceiling_color = line + 2;
	else
	{
		printf("Erro: chave inválida%s\n", line);
		free_all(game);
	}
	return ;
}

static int	is_map_line(char *line)
{
	while (*line && isspace((unsigned char)*line))
		line++;
	return (*line == '1' || *line == '0' || *line == ' ');
}

void	parse_game(t_game *game, char **lines)
{
	int	i;
	int	qtd_lines;

	i = 0;
	qtd_lines = 0;
	game->map = NULL;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
		{
			game->map = realloc(game->map, sizeof(char *) * (qtd_lines + 2));
			game->map[qtd_lines++] = strdup(lines[i]);
			game->map[qtd_lines] = NULL;
		}
		else
			parse_line(game, lines[i]);
		i++;
	}
}
