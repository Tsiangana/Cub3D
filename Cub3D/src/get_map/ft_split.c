/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:00:06 by ctuiango          #+#    #+#             */
/*   Updated: 2024/09/13 17:00:09 by ctuiango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

char	*alocate_word(char *start, int len)
{
	int		i;
	char	*word;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	free_split(char **matriz)
{
	int	i;

	i = 0;
	if (matriz)
	{
		while (matriz[i])
		{
			free(matriz[i]);
			i++;
		}
		free(matriz);
	}
}

char	**alocate_matriz(int word)
{
	char	**matriz;

	matriz = malloc(sizeof(char *) * (word + 1));
	if (!matriz)
		return (NULL);
	matriz[word] = '\0';
	return (matriz);
}

void	fill_matriz(char **matriz, char *s)
{
	int	y;
	int	start;

	y = 0;
	while (*s)
	{
		while (*s && delimeter(*s))
			s++;
		if (*s && !delimeter(*s))
		{
			start = 0;
			while (s[start] && !delimeter(s[start]))
				start++;
			matriz[y] = alocate_word(s, start);
			if (!matriz[y])
			{
				free_split(matriz);
				return ;
			}
			y++;
			s += start;
		}
	}
}

char	**ft_split(char *s)
{
	int		word;
	char	**matriz;

	word = count_words(s);
	matriz = alocate_matriz(word);
	if (!matriz)
		return (NULL);
	fill_matriz(matriz, s);
	return (matriz);
}
