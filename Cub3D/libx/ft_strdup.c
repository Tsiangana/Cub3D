/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:40:00 by pzau              #+#    #+#             */
/*   Updated: 2025/01/27 12:40:03 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*new;

	len = 0;
	while (str[len])
		len++;
	new = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[len])
	{
		new[len] = str[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}
