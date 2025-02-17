/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:46:50 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 01:48:28 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	process_special_keys(int keycode, t_vars *vars)
{
	if (keycode == 65288 || keycode == 65307)
		close_x(vars);
	return (0);
}
