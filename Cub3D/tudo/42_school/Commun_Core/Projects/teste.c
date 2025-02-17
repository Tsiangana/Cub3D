/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:07:09 by pzau              #+#    #+#             */
/*   Updated: 2024/07/28 22:47:16 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void espera_tempo(int segundos)
{
    int contador = 0;

    while (contador < segundos)
    {
        // Loop vazio para simular a espera
        int ciclos = 0;
        while (ciclos < 100000) 
	{
            ciclos++;
        }
        contador++;
    }
}

void	more()
{
	int ciclos = 0;
    
    while (ciclos < 10000)
    {
    	espera_tempo(6);
	ciclos++;
    }
}

int	main(void)
{
	printf("teste\n");
	more();
	printf("test2\n");
	more();
	printf("test3\n");
	return (0);
	
	//pegar localizacao do mouse
	//ft_printf("  Botão 1 clicado em: x=%d, y=%d\n\n", x, y);
	
	/*printf("Level One: x=%d, y=%d\n", vals->level_one_x, vals->level_one_y);
        printf("Level Two: x=%d, y=%d\n", vals->level_two_x, vals->level_two_y);
        printf("Level Three: x=%d, y=%d\n", vals->level_three_x, vals->level_three_y);*
}
