/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:29:07 by pzau              #+#    #+#             */
/*   Updated: 2025/01/17 11:38:21 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Usaremos a geometria nesse projeto saber onde encontrar as paredes 
// no jogo, durante a execucao dele

#include <stdio.h>

void	intersecao_vertical(double x_v, double m, double b, double *x_intersec, double *y_intersec)
{
	*x_intersec = x_v;
	*y_intersec = m * x_v + b;
}

int	main()
{
	double m = 2.0;
	double b = 1.0;
	double x_v = 3.0;
	double x_intersec, y_intersec;

	intersecao_vertical(x_v, m, b, &x_intersec, &y_intersec);
	printf("Interseção com a linha vertical em x = %.2f:\n", x_v);
	printf("Ponto: (%.2f, %.2f)\n", x_intersec, y_intersec);

	return 0;
}

