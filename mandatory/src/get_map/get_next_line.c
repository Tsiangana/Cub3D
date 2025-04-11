/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:16:06 by pzau              #+#    #+#             */
/*   Updated: 2025/01/25 12:16:08 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	get_size(int fd, t_game *game)
{
	int		i;
	int		largura;
	int		altura;
	char	buffer;

	altura = 0;
	largura = 0;
	i = 0;
	game->height = 0;
	game->width = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '\n')
		{
			if (i == 0)
				largura++;
		}
		if (buffer == '\n')
		{
			i = 1;
			altura++;
		}
	}
	game->height = altura;
	game->width = largura;
}

void	open_get_size(char *mapa, t_game *game)
{
	int	fd;

	fd = open(mapa, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nEmpty");
		exit(0);
	}
	get_size(fd, game);
}
