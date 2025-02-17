/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:23:36 by pzau              #+#    #+#             */
/*   Updated: 2024/08/10 10:44:38 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	my_sleep(void)
{
	int	ciclos;

	ciclos = 0;
	while (ciclos < 10000)
	{
		espera_tempo(5);
		ciclos++;
	}
	return (0);
}

/*mini sleep */
void	mini_sleep_a(int segundos)
{
	int	contador;
	int	ciclos;

	contador = 0;
	while (contador < segundos)
	{
		ciclos = 0;
		while (ciclos < 100000)
		{
			ciclos++;
		}
		contador++;
	}
}

void	mini_sleep(void)
{
	int	ciclos;

	ciclos = 0;
	while (ciclos < 10000)
	{
		mini_sleep_a(6);
		ciclos++;
	}
}
/* mini sleep */

/*Split funct*/
int	delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ft_split(char *s)
{
	int		x;
	int		y;
	char	**matrix;

	y = 0;
	while (*s && delimiter(*s))
		s++;
	matrix = malloc(sizeof(char *) * 256);
	while (*s)
	{
		x = 0;
		matrix[y] = malloc(sizeof(char *) * 512);
		while (*s && !delimiter(*s))
			matrix[y][x++] = *(s++);
		while (*s && delimiter(*s))
			s++;
		matrix[y][x] = '\0';
		y++;
	}
	matrix[y] = NULL;
	return (matrix);
}
/*Split funct*/
