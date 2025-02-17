/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:33:29 by pzau              #+#    #+#             */
/*   Updated: 2024/08/29 13:00:18 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	particiona(int *v, int inicio, int fim)
{
	int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3;

	while (inicio < fim)
	{
		while (inicio < fim && v[inicio] <= pivo)
			inicio++;
		while (inicio < fim && v[fim] > pivo)
			fim--;
		int aux = v[inicio];
		v[inicio] = v[fim];
		v[fim] = aux;
	}
	return (inicio);
}

void	quickSort(int *v, int inicio, int fim)
{
	if (inicio < fim)
	{
		int pos = particiona(v, inicio, fim);
		quickSort(v, inicio, pos - 1);
		quickSort(v, pos, fim);
	}
}

void	imprimir(int *v, int tam)
{
	int i;

	for (i = 0; i < tam; i++)
		printf("%d, ", v[i]);
	printf("\n");
}

int	main(void)
{
	int	vet[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61};

	printf("Vetor original:\n");
	imprimir(vet, 14);
	quickSort(vet, 0, 14);
	printf("Vetor organizado:\n");
	imprimir(vet, 14);

	return (0);
}
