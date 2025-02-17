/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:41:12 by pzau              #+#    #+#             */
/*   Updated: 2024/08/10 15:41:48 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_new_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	gameend();
	exit(0);
}

int	close_levels(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win_levels);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	gameend();
	exit(0);
}

int	close_level_one(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win_level);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	gameend();
	exit(0);
}

int	cwlo(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win_level_one);
	
	gameend();
	exit(0);
}
