/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:15:44 by pzau              #+#    #+#             */
/*   Updated: 2024/08/11 15:44:33 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*Carregar imagem*/
int	init_image(t_vars *vars)
{
	vars->bg_img = mlx_xpm_file_to_image(vars->mlx,
			"game_assets/intro.xpm", &(vars->bg_width), &(vars->bg_height));
	if (!vars->bg_img)
		exit(1);
	return (0);
}

int	back_image(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx,
			"game_assets/level.xpm", &(vars->img_width), &(vars->img_height));
	if (!vars->img)
		exit(1);
	return (0);
}

int	back_image_w(t_vars *vars)
{
	vars->img_w = mlx_xpm_file_to_image(vars->mlx,
			"game_assets/wt.xpm", &(vars->img_width_w), &(vars->img_height_w));
	if (!vars->img_w)
		exit(1);
	return (0);
}

int	back_image_levels(t_vars *vars)
{
	vars->img_level = mlx_xpm_file_to_image(vars->mlx,
			"gs/ls.xpm", &(vars->img_width_level), &(vars->img_height_level));
	if (!vars->img_level)
		exit(1);
	return (0);
}
/*Carregar imagem*/

/*Carregar imagens no mapa*/
void	load_imagens(t_vars *vars)
{
	vars->img_0 = mlx_xpm_file_to_image(vars->mlx,
			"gs/box.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_p = mlx_xpm_file_to_image(vars->mlx,
			"gs/player.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_c = mlx_xpm_file_to_image(vars->mlx,
			"gs/collect.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_e = mlx_xpm_file_to_image(vars->mlx,
			"gs/door.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_wall = mlx_xpm_file_to_image(vars->mlx,
			"gs/wall.xpm", &vars->img_width_img, &vars->img_height_img);
	vars->img_enemy = mlx_xpm_file_to_image(vars->mlx,
			"gs/three.xpm", &vars->img_width_img, &vars->img_height_img);
}
/*Carregar imagens no mapa*/
