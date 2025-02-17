/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:48:15 by pzau              #+#    #+#             */
/*   Updated: 2024/08/11 16:14:54 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_back_one(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 65288)
	{
		mlx_destroy_window(vars->mlx, vars->win_level);
		ft_printf("  Regressando a tela dos niveis\n\n");
		levels_page(vars);
	}
}

int	key_back_two(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 65288)
	{
		mlx_destroy_window(vars->mlx, vars->win_level_one);
		ft_printf("  Regressando a tela dos niveis\n\n");
		levels_page(vars);
	}
}

int	key_back_three(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == 65288)
	{
		mlx_destroy_window(vars->mlx, vars->win_level_two);
		ft_printf("  Regressando a tela dos niveis\n\n");
		levels_page(vars);
	}
}

int	iniciar(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		if (x >= vars->x_pos && x <= vars->x_pos + vars->small_width
			&& y >= vars->y_pos && y <= vars->y_pos + vars->small_height)
		{
			ft_printf("  Selecione seu nivel! \n\n");
			destroy_main_window(vars);
			levels_page(vars);
		}
	}
	return (0);
}
