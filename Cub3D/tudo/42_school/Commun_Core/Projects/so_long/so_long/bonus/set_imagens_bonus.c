/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_imagens_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:55:00 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 06:52:56 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	load_imagens(t_vars *vars)
{
	vars->img_0 = mlx_xpm_file_to_image(vars->mlx,
			"img/box.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_p = mlx_xpm_file_to_image(vars->mlx,
			"img/player.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_c = mlx_xpm_file_to_image(vars->mlx,
			"img/collect.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_e = mlx_xpm_file_to_image(vars->mlx,
			"img/door.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx,
			"img/wall.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_enemy = mlx_xpm_file_to_image(vars->mlx,
			"img/enen.xpm", &vars->img_width_img, &vars->img_height_img);
}

void	free_images(t_vars *vars)
{
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
