/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:08:09 by lmachado          #+#    #+#             */
/*   Updated: 2025/04/10 15:15:27 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	get_color(char *line)
{
	int		number[3];
	char	**split;
	int		i;

	split = ft_split_1(line + 2, ',');
	i = -1;
	while (split && split[++i])
		number[i] = ft_atoi(line);
	free_split(split);
	return (number[0] << 16 | number[1] << 8 | number[2]);
}

int	num_comma(char *line)
{
	int	i;
	int	cont;

	cont = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ',')
			cont++;
	}
	return (cont);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == ','))
			i++;
		else
			return (1);
	}
	return (0);
}

static int	are_valid_color_numbers(char **split)
{
	int	i;
	int	number;

	i = -1;
	while (split && split[++i])
	{
		if (check_number(split[i]))
			return (0);
		number = ft_atoi(split[i]);
		if (number < 0 || number > 255)
			return (0);
	}
	if (i != 3)
		return (0);
	return (1);
}

int	is_valid_color(char *line)
{
	char	**split;

	if (!line)
		return (1);
	if (num_comma(line) != 2)
		return (1);
	split = ft_split_1(line, ',');
	if (!are_valid_color_numbers(split))
	{
		free_split(split);
		return (1);
	}
	free_split(split);
	return (0);
}
