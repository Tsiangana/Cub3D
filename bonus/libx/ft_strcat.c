/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:40:15 by pzau              #+#    #+#             */
/*   Updated: 2025/01/27 12:40:16 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_strcat(char *dest, char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[len])
		len++;
	while (str[i])
	{
		dest[len] = str[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
