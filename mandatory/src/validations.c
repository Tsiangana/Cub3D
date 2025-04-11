/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:29:41 by lmachado          #+#    #+#             */
/*   Updated: 2025/04/10 15:18:47 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	check_arguments(int ac, char **av, t_game *game)
{
	if (ac != 2)
	{
		write(2, "Error!\n Incorrect arguments \n", 30);
		exit(1);
	}
	if (strlen(av[1]) < 4 || !strchr(av[1], '.') || strcmp(".cub", av[1]
			+ strlen(av[1]) - 4) != 0)
	{
		write(2, "Error!\n Incorrect extension \n", 30);
		exit(1);
	}
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
	{
		write(2, "Error!\n", 1);
		write(2, strerror(errno), strlen(strerror(errno)));
		exit(1);
	}
}

int	verify_extension(char *str)
{
	int	c;

	c = 1;
	if (str == NULL)
		return (1);
	if (str[0] != '.' && str[1] != '/')
		return (1);
	while (str[c])
	{
		if (str[c] == '.')
		{
			c++;
			if (str[c] == 'x' && str[c + 1] == 'p' && str[c + 2] == 'm')
				return (0);
			else
				return (1);
		}
		c++;
	}
	return (1);
}

static int	return_values(char *str, int *i)
{
	int	k;
	int	j;

	k = 0;
	while (str[k] != '\0' && str[k + 3] != '\0')
	{
		if ((str[k] == '1' && str[k + 1] == '1'
				&& str[k + 2] == '1' && str[k + 3] == '1'))
			break ;
		k++;
	}
	j = 0;
	while (str[j] != '\0')
		(j)++;
	while (j > 0)
	{
		if (str[j] == '1')
			break ;
		j--;
	}
	*i = j;
	return (k);
}

void	verifybreakline(char *str)
{
	int	i;
	int	k;

	k = return_values(str, &i);
	while (k < i)
	{
		if (k + 1 < i)
		{
			if (str[k] == '\n' && str[k + 1] == '\n')
			{
				printf("error: Mapa invalido\n");
				free(str);
				exit(1);
			}
		}
		k++;
	}
	aux_verifybreakline(str);
}

int	verify_characters(t_game *game)
{
	char	c;
	int		x;
	int		y;
	int		count;

	count = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			c = game->map[y][x];
			aux_verify_characters(c);
			if (c == 'W' || c == 'N' || c == 'S' || c == 'E')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (1);
	return (0);
}
