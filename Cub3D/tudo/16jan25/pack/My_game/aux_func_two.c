/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:53:00 by pzau              #+#    #+#             */
/*   Updated: 2024/08/10 10:55:07 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	gamestart(void)
{
	ft_printf("\n\n");
	ft_printf("  ***** ***** ***** *****  ***** \n");
	ft_printf("  *       *   *   * *    *   *   \n");
	ft_printf("  *****   *   ***** *****    *   \n");
	ft_printf("      *   *   *   * *   *    *   \n");
	ft_printf("  *****   *   *   * *    *   *   \n\n");
}

void	gameend(void)
{
	ft_printf("  ***** *    *  ****  \n");
	ft_printf("  *     **   *  *   * \n");
	ft_printf("  ***** * *  *  *   * \n");
	ft_printf("  *     *  * *  *   * \n");
	ft_printf("  ***** *   **  ****  \n\n");
}

void	youwin(void)
{
	ft_printf("  *      * ***** *    * \n");
	ft_printf("  *  *   *   *   **   * \n");
	ft_printf("  *  **  *   *   * *  * \n");
	ft_printf("  * *  * *   *   *  * * \n");
	ft_printf("  **    ** ***** *   ** \n\n");
}

void	youlose(void)
{
	ft_printf("  *     ***** ***** ***** \n");
	ft_printf("  *     *   * *     *     \n");
	ft_printf("  *     *   * ***** ***** \n");
	ft_printf("  *     *   *     * *     \n");
	ft_printf("  ***** ***** ***** ***** \n\n");
}

void	espera_tempo(int segundos)
{
	int	contador;
	int	ciclos;

	contador = 0;
	while (contador < segundos)
	{
		ciclos = 0;
		while (ciclos < 100000)
		{
			ciclos++;
		}
		contador++;
	}
}
