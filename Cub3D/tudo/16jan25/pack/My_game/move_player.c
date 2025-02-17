/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:33:52 by pzau              #+#    #+#             */
/*   Updated: 2024/08/11 14:46:18 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_player_position(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	vars->coletaveis = 0;
	while (y < vars->dim.altura)
	{
		x = 0;
		while (x < vars->dim.largura)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x_pos = x;
				vars->y_pos = y;
				return ;
			}
			else if (vars->map[y][x] == 'C')
				vars->coletaveis++;
			x++;
		}
		y++;
	}
}
