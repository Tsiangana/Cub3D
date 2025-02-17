/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:01:34 by pzau              #+#    #+#             */
/*   Updated: 2024/08/13 06:29:53 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include "header.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_window_and_images(t_vars *vars, void *win)
{
	if (win)
		mlx_destroy_window(vars->mlx, win);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->img_w)
		mlx_destroy_image(vars->mlx, vars->img_w);
	if (vars->img_level)
		mlx_destroy_image(vars->mlx, vars->img_level);
	if (vars->start_img)
		mlx_destroy_image(vars->mlx, vars->start_img);
	if (vars->small_img)
		mlx_destroy_image(vars->mlx, vars->small_img);
	if (vars->bg_img)
		mlx_destroy_image(vars->mlx, vars->bg_img);
	if (vars->img_0)
		mlx_destroy_image(vars->mlx, vars->img_0);
	if (vars->img_p)
		mlx_destroy_image(vars->mlx, vars->img_p);
	if (vars->img_c)
		mlx_destroy_image(vars->mlx, vars->img_c);
	if (vars->img_e)
		mlx_destroy_image(vars->mlx, vars->img_e);
	if (vars->img_wall)
		mlx_destroy_image(vars->mlx, vars->img_wall);
	if (vars->img_enemy)
		mlx_destroy_image(vars->mlx, vars->img_enemy);
}

void	destroy_level_windows(t_vars *vars)
{
	if (vars->win_level_one)
		mlx_destroy_window(vars->mlx, vars->win_level_one);
	if (vars->win_level_two)
		mlx_destroy_window(vars->mlx, vars->win_level_two);
	if (vars->win_level)
		mlx_destroy_window(vars->mlx, vars->win_level);
	if (vars->win_w)
		mlx_destroy_window(vars->mlx, vars->win_w);
	if (vars->win_levels)
		mlx_destroy_window(vars->mlx, vars->win_levels);
}

void	cleanup_all_resources(t_vars *vars)
{
	if (!vars)
		return;
	free_map(vars->map);
	destroy_window_and_images(vars, vars->win);
	destroy_level_windows(vars);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}


int	main(void)
{
	t_vars	vars;
	t_vals	vals;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 519, "so_long");
	vals.pin_level = 0;
	init_image(&vars);
	draw_small_image(&vars);
	mlx_mouse_hook(vars.win, iniciar, &vars);
	mlx_hook(vars.win, 17, 0, close_new_window, &vars);
	mlx_key_hook(vars.win, key_esc, &vars);
	gamestart();
	mlx_loop(vars.mlx);
	cleanup_all_resources(&vars);
	return (0);
}
