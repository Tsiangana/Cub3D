/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:38:05 by ctuiango          #+#    #+#             */
/*   Updated: 2025/04/10 14:24:32 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
