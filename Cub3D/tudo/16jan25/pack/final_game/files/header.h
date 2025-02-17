/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:57:11 by pzau              #+#    #+#             */
/*   Updated: 2024/10/09 11:57:13 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"

# define PIX 50

typedef struct s_vars
{
    void    *mlx;
    void    *win;
}   t_vars;

#endif
