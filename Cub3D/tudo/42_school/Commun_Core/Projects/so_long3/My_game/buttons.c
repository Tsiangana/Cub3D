/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:02:38 by pzau              #+#    #+#             */
/*   Updated: 2024/08/13 05:19:12 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* Start button */
void	draw_small_image(t_vars *vars)
{
	vars->small_img = mlx_xpm_file_to_image(vars->mlx,
			"gs/st.xpm", &(vars->small_width), &(vars->small_height));
	if (!vars->small_img)
	{
		ft_printf("  Erro ao carregar imagem do botao start\n\n");
		exit(1);
	}
	vars->x_pos = (vars->bg_width - vars->small_width) / 2;
	vars->y_pos = (vars->bg_height - vars->small_height) / 2;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg_img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->small_img, vars->x_pos, vars->y_pos);
}

void	buttons_start(t_vars *vars, t_vals *vals)
{
	int	btn_width;
	int	btn_height;
	int	spacing;
	int	total_width;
	int	start_x;

	btn_width = vals->level_one_width;
	btn_height = vals->level_one_height;
	spacing = 20;
	total_width = (3 * btn_width) + (2 * spacing);
	start_x = (900 - total_width) / 2;
	vars->last_y = (506 - btn_height) / 2;
	vals->level_one_x = start_x;
	vals->level_one_y = vars->last_y;
	vals->level_two_x = start_x + btn_width + spacing;
	vals->level_two_y = vars->last_y;
	vals->level_three_x = start_x + 2 * (btn_width + spacing);
	vals->level_three_y = vars->last_y;
	mlx_put_image_to_window(vars->mlx, vars->win_levels,
		vals->level_one, vals->level_one_x, vals->level_one_y);
	mlx_put_image_to_window(vars->mlx, vars->win_levels,
		vals->level_two, vals->level_two_x, vals->level_two_y);
	mlx_put_image_to_window(vars->mlx, vars->win_levels,
		vals->level_three, vals->level_three_x, vals->level_three_y);
}
