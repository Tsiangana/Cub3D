/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:38:01 by pzau              #+#    #+#             */
/*   Updated: 2024/09/18 19:09:13 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE_H
# define BUFFER_SIZE 43
#endif

char	*ft_strdup(char *str)
{
	char *new;
	int i = 0;

	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char	str[7000000];
	static int pos;
	static int size;
	int i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= size)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (size <= 0)
				break ;
		}
		str[i++] = buffer[pos++];
		if (str[i - 1] == '\n')
			break ;
	}
	str[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(str));
}
