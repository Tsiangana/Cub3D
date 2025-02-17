/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:15:19 by pzau              #+#    #+#             */
/*   Updated: 2024/09/24 19:26:35 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void	*routine()
{
	x++;
	sleep(2);
	printf("value of x: %d\n", x);
}

void	*routine2()
{
	sleep(2);
	printf("value of x: %d\n", x);
}

int	main(int ac, char **av)
{
	pthread_t	t1, t2;

	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t2, NULL, &routine2, NULL))
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (4);
	return (0);
}
