/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:12:24 by ctuiango          #+#    #+#             */
/*   Updated: 2024/09/16 10:12:31 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	delimeter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
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
