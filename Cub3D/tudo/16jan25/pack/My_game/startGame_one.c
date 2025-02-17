/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startGame_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:52:18 by pzau              #+#    #+#             */
/*   Updated: 2024/08/10 17:53:25 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	destroy_main_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
}

void	destroy_level_page(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win_levels);
	vars->win_levels = NULL;
}

void	destroy_waiting(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win_w);
	vars->win = NULL;
}
