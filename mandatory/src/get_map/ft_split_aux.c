/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:12:24 by pzau              #+#    #+#             */
/*   Updated: 2025/04/10 14:25:17 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	delimeter(char c)
{
	return (c == '\n');
}

int	count_words(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && delimeter(*str))
			str++;
		if (*str && !delimeter(*str))
		{
			cnt++;
			while (*str && !delimeter(*str))
				str++;
		}
	}
	return (cnt);
}
