/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:07:35 by pzau              #+#    #+#             */
/*   Updated: 2025/01/17 12:12:05 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A distancia euclideana e usada para melhorar a qualidade dos pixes durante a renderizacao
// determina o comprimentomdo raio desde a posicao inicial ate o ponto de 
// intersecao com uma parede

#include <stdio.h>
#include <math.h>

double	distancia_euclidiana(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int	main()
{
	double x1 = 1.0, y1 = 2.0;
	double x2 = 4.0, y2 = 6.0;

	double distancia = distancia_euclidiana(x1, y1, x2, y2);
	printf("A distância euclidiana entre os pontos (%.2f, %.2f) e (%.2f, %.2f) é: %.2f\n", x1, y1, x2, y2, distancia);
	return 0;
}
