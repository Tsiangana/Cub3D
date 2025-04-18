/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:36:23 by pzau              #+#    #+#             */
/*   Updated: 2025/04/10 14:26:13 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

char	*alocate_space(char *content, char *buffer)
{
	char	*new_var;
	char	*temp;

	temp = content;
	if (content == NULL)
		new_var = ft_strdup(buffer);
	else
		new_var = ft_strcat(ft_strdup(content), buffer);
	if (temp)
		free(temp);
	return (new_var);
}

void	verify_empty_map(char *str)
{
	int	i;
	int	on;

	i = 0;
	on = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
			on++;
		i++;
	}
	if (on == 0)
	{
		printf("Error: Mapa invalido\n");
		free(str);
		exit(1);
	}
}

char	**print_map(char *str)
{
	char	*cont_get;
	char	**cont_split;
	t_bytes	bit;

	cont_get = get_nextline(str, &bit);
	verify_empty_map(cont_get);
	verifybreakline(cont_get);
	cont_split = ft_split(cont_get);
	free(cont_get);
	return (cont_split);
}
