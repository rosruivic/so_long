/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   250_right_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:13:23 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 01:10:10 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*****************************************************************/
/*************      VERIYING A PLAYABLE PATH			****************/
/*****************************************************************/

static void	ft_compare_maps(t_bag *data)
{
	int	i;

	i = -1;
	if (data->twin[data->exi.y][data->exi.x] != 'F')
	{
		ft_error_msg(data, ERROR_NO_PATH);
		return ;
	}
	while (++i < data->n_collec)
	{
		if (data->twin[data->co[i].y][data->co[i].x] != 'F')
		{
			ft_error_msg(data, ERROR_NO_PATH);
			return ;
		}
	}
}

/**
 * @brief This recursive ft multiply each mov to a new search of "void",
 * 		"exit" & "collect" places, and then it marks them into "F", to
 * 		representate an available path from player to colectables & exit.
 * 
 * @param p_x 	Initial player coordinate "x", then coord "x" after a movmnt
 * @param p_y 	Initial player coordinate "y", then coord "y" after a movmnt
 * @param data 
 */
static void	ft_flood_fill(int p_x, int p_y, t_bag *data)
{
	data->twin[p_y][p_x] = 'F';
	if (data->twin[p_y - 1][p_x] != '1' && data->twin[p_y - 1][p_x] != 'F')
	{
		ft_flood_fill(p_x, p_y - 1, data);
	}
	if (data->twin[p_y + 1][p_x] != '1' && data->twin[p_y + 1][p_x] != 'F')
	{
		ft_flood_fill(p_x, p_y + 1, data);
	}
	if (data->twin[p_y][p_x - 1] != '1' && data->twin[p_y][p_x - 1] != 'F')
	{
		ft_flood_fill(p_x - 1, p_y, data);
	}
	if (data->twin[p_y][p_x + 1] != '1' && data->twin[p_y][p_x + 1] != 'F')
	{
		ft_flood_fill(p_x + 1, p_y, data);
	}
}

static void	ft_twin_map(t_bag *data)
{
	int	i;

	i = -1;
	data->twin = ft_calloc(data->dim.y + 1, sizeof(char *));
	if (!data->twin)
	{
		data->flag = 'n';
		return ;
	}
	while (++i < data->dim.y)
	{
		data->twin[i] = ft_strdup(data->map[i]);
		if (data->twin[i] == NULL)
		{
			data->flag = 'n';
			ft_freedom(data->twin);
			return ;
		}
	}
}

void	ft_right_path(t_bag *data)
{
	if (data->flag == 'n')
		return ;
	ft_twin_map(data);
	if (data->flag == 'n')
		return ;
	ft_flood_fill(data->ply.x, data->ply.y, data);
	ft_compare_maps(data);
	if (data->flag == 'n')
	{
		ft_freedom(data->map);
		free(data->co);
	}
	ft_freedom(data->twin);
}
