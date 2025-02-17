/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:43:02 by pzau              #+#    #+#             */
/*   Updated: 2024/08/10 15:43:38 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	cwto(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win_level_two);
	gameend();
	exit(0);
}

int	key_esc(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		gameend();
		exit(0);
	}
	return (0);
}
