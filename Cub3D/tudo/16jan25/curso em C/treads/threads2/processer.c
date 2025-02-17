/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:15:42 by pzau              #+#    #+#             */
/*   Updated: 2024/09/24 19:26:41 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int	main(int ac, char **av)
{
	int	x = 2;
	int pid = fork();

	if (pid == -1)
		return 1;
	if (pid == 0)
		x++;
	sleep(2);
	printf("Value of x: %d\n", x);
	if (pid != 0)
		wait(NULL);

	return (0);
}
