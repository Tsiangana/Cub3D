/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:34:03 by pzau              #+#    #+#             */
/*   Updated: 2025/01/31 12:34:04 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/game.h"

void    responsivo(t_game *game)
{
    if (game->DEBUG == 0)
    {
        game->HEIGHT = 720;
        game->WIDTH = 1280;
    }
    if (game->DEBUG == 1 && ((game->height * 64 < 720) && (game->width * 64 < 1280)))
    {
        game->HEIGHT = game->height * 64;
        game->WIDTH = game->width * 64;
    }
    if (game->DEBUG == 1 && ((game->height * 64 > 720) && (game->width * 64 > 1280)))
        printf("error\nmap too big to open in 2d mode\n");
}
