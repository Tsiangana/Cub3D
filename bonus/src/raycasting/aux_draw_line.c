/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:15:01 by pzau              #+#    #+#             */
/*   Updated: 2025/03/17 13:15:03 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float y1, float y2, t_game *game)
{
	float	delta_x;
	float	dela_y;
	float	angle;
	float	fix_dist;

	delta_x = game->x2 - game->x1;
	dela_y = y2 - y1;
	angle = atan2(dela_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, dela_y) * cos(angle);
	return (fix_dist);
}
