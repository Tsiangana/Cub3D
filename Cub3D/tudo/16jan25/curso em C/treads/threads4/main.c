/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:59:49 by pzau              #+#    #+#             */
/*   Updated: 2024/09/26 12:30:02 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int ac, char **av)
{
	pthread_t th[8];
	int	i;

	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 8; i++)
	{
		if (pthread_create(th + i, NULL, &routine, NULL) != 0)
		{
			perror("Failed to create thread");
                	return (1);
		}
		printf("Threads %d has started\n", i);
	}
	for (i = 0; i < 8; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (2);
		printf("Threads %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}
