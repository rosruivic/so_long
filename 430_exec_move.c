/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   430_exec_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:09:13 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/09/10 18:44:39 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************** */
/* ****************      MOVING THE PLAYER        ***************** */
/* ****************       & PRINTING MOVES        ***************** */
/* **************************************************************** */

static void	ft_exec_up(t_bag *data)
{
	data->im.bee_r->instances[0].y -= P;
	data->ply.y = data->ply.y - 1;
}

static void	ft_exec_left(t_bag *data)
{	
	data->im.bee_r->instances[0].x -= P;
	data->ply.x = data->ply.x - 1;
}

static void	ft_exec_right(t_bag *data)
{
	data->im.bee_r->instances[0].x += P;
	data->ply.x = data->ply.x + 1;
}

static void	ft_exec_down(t_bag *data)
{
	data->im.bee_r->instances[0].y += P;
	data->ply.y = data->ply.y + 1;
}

void	ft_exec_move(t_bag *data, char m)
{
	if (m == 'U')
		ft_exec_up(data);
	else if (m == 'D')
		ft_exec_down(data);
	else if (m == 'L')
		ft_exec_left(data);
	else if (m == 'R')
		ft_exec_right(data);
}
