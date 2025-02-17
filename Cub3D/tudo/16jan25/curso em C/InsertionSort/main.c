/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:27:20 by pzau              #+#    #+#             */
/*   Updated: 2024/08/29 18:00:22 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    insertionSortRecursivo(int *v, int fim, int tam);

void	insertionSort(int *v, int tam)
{
	int	i, j;

	for (i = 1; i < tam; i++)
	{
		int aux, j = i;
		aux = v[j];
		while (j > 0 && aux < v[j -1])
		{
			v[j] = v[j - 1];
			j--;
		}
		v[j] = aux;
	}
}

void	insertionSortRecursivo(int *v, int fim, int tam)
{
	if (fim >= tam)
		return ;

	int aux;
	int j = fim;

	aux = v[j];
	while (j > 0 && aux < v[j - 1])
	{
		v[j] = v[j - 1];
		j--;
	}
	v[j] = aux;
	insertionSortRecursivo(v, fim + 1, tam);
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
	int vet[] = {7,5,10,3,9,8,1,4,2,0,6};
	int tam = 11;

	printf("Vetor original:  ");
	imprimir(vet, tam);
	printf("\n");
	insertionSort(vet, tam);
	//insertionSortRecursivo(vet, 1, tam);
	printf("Vetor antigo:   ");
	imprimir(vet, tam);

	return (0);
}
