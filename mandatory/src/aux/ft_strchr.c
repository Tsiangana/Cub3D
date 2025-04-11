/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:56:29 by lmachado          #+#    #+#             */
/*   Updated: 2025/04/11 10:34:34 by lmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*str;
	char	character;

	str = (char *)s;
	character = (unsigned char)c;
	count = -1;
	while (s[++count] != '\0')
		if (s[count] == character)
			return (&str[count]);
	if (character == '\0')
		return (&str[count]);
	return (0);
}
