/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:05:01 by pzau              #+#    #+#             */
/*   Updated: 2025/01/24 13:05:02 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "./mlx/mlx.h"
#include "../libx/libx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <math.h>

typedef struct s_pages
{
    void    *page[4];
    void    *buttons[4];
    int width[4];
    int height[4];
    int w_button[4];
    int h_button[4];
}   t_pages;

typedef struct s_game
{
    void    *mlxs[4];
    void    *wins[4];

    t_pages page;
}   t_game;

void    start_page_one(t_game *game, t_pages *pages);
void    start_page_two(t_game *game);
void    page_three(t_game *game);
int start_button(int button, int x, int y, t_game *game);
int CloseWindow(t_game *game);
int Closet(t_game *game);

#endif
