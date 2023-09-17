/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   440_polin_or_dead.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:02:25 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 00:57:19 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************** */
/* ****************		  	CHANGES IMAGES OF				***************** */
/* ****************		-	HERV & CARNIV FLOWERS - 	***************** */
/* **************************************************************** */

/**
 * @brief Comprobamos con el array de collectables cuál flor coincide
 * 	las coordenadas con las coordenadas del jugador, y la disableamos 
 * @param data 
 */
void	ft_polinized_flower(t_bag *data)
{
	int	i;

	i = -1;
	while (++i < data->n_collec)
	{
		if (data->co[i].x == data->ply.x && data->co[i].y == data->ply.y)
		{
			data->im.co->instances[i].enabled = false;
			data->im.pol->instances[i].enabled = true;
		}
	}
}

void	ft_full_hive(t_bag *data)
{
	data->im.hiv->instances[0].enabled = true;
}
