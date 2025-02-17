/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:05:11 by pzau              #+#    #+#             */
/*   Updated: 2024/09/27 09:11:57 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void	*routine(void *arg)
{
	int index = *(int*)arg;
	int sum = 0;
	for (int j = 0; j < 5; j++)
	{
		sum += primes[index + j];
	}
	printf("Local sum: %d\n", sum);
	*(int*)arg = sum;
	return (arg);
}

int	main(int av, char **ac)
{
	pthread_t th[2];
	int i;
	for (i = 0; i < 2; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create threads");
	}
	int global_sum = 0;
	for (i = 0; i < 2; i++)
	{
		int *r;
		if (pthread_join(th[i], (void **)&r) != 0)
			perror("Failed to join thread");
		global_sum += *r;
		free(r);
	}
	printf("Global sum: %d\n", global_sum);
	return (0);
}
