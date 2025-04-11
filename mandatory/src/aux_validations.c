/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:00:26 by lmachado          #+#    #+#             */
/*   Updated: 2025/04/11 10:42:46 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	aux_verifybreakline(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		if (str[i] != ' ' && str[i] != '\n')
		{
			if (str[i] != '1')
			{
				printf("error: Mapa invalido\n");
				free(str);
				exit(1);
			}
			break ;
		}
		i--;
	}
}

int	aux_verify_characters(int c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ' && c != '\n' && c != '\t')
		return (1);
}

int	has_invalid_zero_around(t_game *game, int y, int x)
{
	if ((y > 0 && x < (int)ft_strlen(game->map[y - 1]) && game->map[y
				- 1][x] == '0') || (game->map[y + 1] != NULL
			&& x < (int)strlen(game->map[y + 1]) && game->map[y + 1][x] == '0')
		|| (x > 0 && game->map[y][x - 1] == '0') || (x
			+ 1 < (int)ft_strlen(game->map[y]) && game->map[y][x + 1] == '0'))
	{
		return (1);
	}
	return (0);
}

int	verify_space(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == ' ' && has_invalid_zero_around(game, y, x))
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	aux_add_tab(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[game->tab.y][i])
	{
		if (game->map[game->tab.y][i] == '\t')
		{
			game->tab.k = 0;
			while (game->tab.k < TAB_WIDTH)
			{
				game->tab.new_line[j++] = ' ';
				game->tab.k++;
			}
		}
		else
			game->tab.new_line[j++] = game->map[game->tab.y][i];
		i++;
	}
}
