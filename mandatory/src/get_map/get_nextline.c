/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:04:23 by ctuiango          #+#    #+#             */
/*   Updated: 2024/09/16 11:05:48 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	close_check(char *content)
{
	free(content);
	exit(1);
}

static void	total_bytes(t_bytes *bit, char *content, int fd)
{
	if (bit->total_bytess > 1024)
	{
		printf("Error\nMap too big!\n");
		free(content);
		close(fd);
		exit(1);
	}
}

static void	extra(void)
{
	perror("Error\n");
	exit(1);
}

char	*get_nextline(char *str, t_bytes *bit)
{
	int		bytes;
	int		fd;
	char	buffer[1025];
	char	*content;

	content = 0;
	bit->total_bytess = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		extra();
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		bit->total_bytess += bytes;
		total_bytes(bit, content, fd);
		content = alocate_space(content, buffer);
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	if (bytes < 0 || content == NULL)
		close_check(content);
	return (content);
}
