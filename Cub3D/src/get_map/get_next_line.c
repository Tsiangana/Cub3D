/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:16:06 by pzau              #+#    #+#             */
/*   Updated: 2025/01/25 12:16:08 by pzau             ###   ########.fr       */
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

char	**get_map(char *str)
{
	char	*cont_get;
	char	**cont_split;
	t_bytes	bit;

	cont_get = get_nextline(str, &bit);
	cont_split = ft_split(cont_get);
	free(cont_get);
	return (cont_split);
}