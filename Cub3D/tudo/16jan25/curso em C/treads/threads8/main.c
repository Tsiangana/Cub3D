/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:13:12 by pzau              #+#    #+#             */
/*   Updated: 2024/09/28 16:28:10 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	if (pthread_mutex_trylock(&mutex) == 0)
	{
		printf("Go lock\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		printf("Didnt't get lock\n");
	}
}

int	main(int ac, char **av)
{
	pthread_t th[4];
	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Error at creating thread");
	}
	for (int i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Error at joining thread");
	}
	return (0);
}
