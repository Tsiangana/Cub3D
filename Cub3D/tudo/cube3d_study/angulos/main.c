/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:23:39 by pzau              #+#    #+#             */
/*   Updated: 2025/01/17 09:34:17 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Essa funcao permite achar ou calcular os radianos de um angulo
// , nesse projetos devemos saber os radianos de um angulo, pois 
// isso que vai nos permiter saber andar pelo mapa sabendo a 
// quantides de passo dados pelo mapa.


#include <math.h>
#include <stdio.h>

void	calcular_nova_posicao(double x_inicial, double y_inicial, double angulo_graus, int passos, double *x_final, double *y_final)
{
	double angulo_radianos = angulo_graus  * M_PI / 180.0;

	double dx = cos(angulo_radianos);
	double dy = sin(angulo_radianos);

	*x_final = x_inicial + passos * dx;
	*y_final = y_inicial + passos * dy;
}

int	main()
{
	double x = 2.0;
	double y = 3.0;
	double angulo = 45.0;
	int passos = 5;

	double x_final, y_final;

	calcular_nova_posicao(x, y, angulo, passos, &x_final, &y_final);

	printf("Nova posicao apos %d passos com angulos %.2f:\n", passos, angulo);
	printf("x_final = %.3f, y_final = %.3f\n", x_final, y_final);

	return (0);
}
