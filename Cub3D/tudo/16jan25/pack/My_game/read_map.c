/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:08:41 by pzau              #+#    #+#             */
/*   Updated: 2024/08/09 18:31:53 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**print_map(const char *filename)
{
	char	buffer[1024];
	int		bytes_read;
	int		fd;

	fd = open(filename, O_RDONLY);
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ft_printf("%s  \n", buffer);
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read < 0)
	{
		ft_printf("Erro ao ler o arquivo");
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (ft_split(buffer));
	close(fd);
}

/*Numero de linhas e colunas*/
void	disp_file(int fd, t_dimensoes *dim)
{
	char	buffer;
	int		flag;
	int		w;
	int		h;

	w = 0;
	h = 0;
	flag = 0;
	dim->altura = 0;
	dim->largura = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '\n')
		{
			if (!flag)
				w++;
		}
		if (buffer == '\n')
		{
			flag = 1;
			h++;
		}
	}
	dim->altura = h;
	dim->largura = w;
}

void	dimention(char *fdf, t_dimensoes *dim)
{
	int	fd;

	fd = open(fdf, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("  Erro ao abrir arquivo dimention\n\n");
	}
	disp_file(fd, dim);
	close(fd);
}
/*Numero de linhas e colunas*/
