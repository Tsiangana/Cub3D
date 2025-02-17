/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:56:35 by pzau              #+#    #+#             */
/*   Updated: 2024/10/01 19:35:44 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

pthread_mutex_t stoveMutex;
int	stoveFuel = 100;

void	*routine(void *arg)
{
	pthread_mutex_lock(&stoveMutex);
	stoveFuel -= (rand() % 20);
	pthread_mutex_unlock(&stoveMutex);
}

int	main(int ac, char **av)
{
	srand(time(NULL));
	pthread_t th[10];
	pthread_mutex_init(&stoveMutex, NULL);
	for (int i = 0; i < 10; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}

	for (int i = 0; i < 10; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	pthread_mutex_destroy(&stoveMutex);
	return (0);
}


int 	main(int ac, char **av)
{
	int i = 0;

	while (i < 10)
	{
		i++;
		if (i == 9)
			break ;
	g
	return (0)
}
