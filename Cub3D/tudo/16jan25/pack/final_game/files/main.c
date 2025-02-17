/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:54:35 by pzau              #+#    #+#             */
/*   Updated: 2024/10/09 11:54:56 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 900, 519, "so_long");
    init_image(&vars);
    draw_small_image
}
