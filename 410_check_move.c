/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   410_check_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:14:32 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 12:38:46 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************** */
/* *****************        CHECKING MOVES        ***************** */
/* **************************************************************** */

/**
 * @brief The bee twist to look up
 * 
 * @param data 
 */
void	ft_up(t_bag *data)
{
	if (data->map[data->ply.y - 1][data->ply.x] == '1')
		return ;
	else if (data->map[data->ply.y - 1][data->ply.x] == 'C')
		ft_move_to_collec(data, 'U');
	else if ((data->map[data->ply.y - 1][data->ply.x] == 'E')
		&& (data->n_collected == data->n_collec))
		ft_move_to_exit(data, 'U');
	else
	{
		ft_exec_move(data, 'U');
		ft_print_moves(data);
	}
}

/**
 * @brief The bee twist to look down
 * 
 * @param data 
 */
void	ft_down(t_bag *data)
{
	if (data->map[data->ply.y + 1][data->ply.x] == '1')
		return ;
	else if (data->map[data->ply.y + 1][data->ply.x] == 'C')
		ft_move_to_collec(data, 'D');
	else if ((data->map[data->ply.y + 1][data->ply.x] == 'E')
		&& (data->n_collected == data->n_collec))
		ft_move_to_exit(data, 'D');
	else
	{
		ft_exec_move(data, 'D');
		ft_print_moves(data);
	}
}

/**
 * @brief The bee twist to look left
 * 
 * @param data 
 */
void	ft_left(t_bag *data)
{
	if (data->map[data->ply.y][data->ply.x - 1] == '1')
		return ;
	else if (data->map[data->ply.y][data->ply.x - 1] == 'C')
		ft_move_to_collec(data, 'L');
	else if ((data->map[data->ply.y][data->ply.x - 1] == 'E')
		&& (data->n_collected == data->n_collec))
		ft_move_to_exit(data, 'L');
	else
	{
		ft_exec_move(data, 'L');
		ft_print_moves(data);
	}
}

/**
 * @brief The bee twist to look right
 * 
 * @param data 
 */
void	ft_right(t_bag *data)
{
	if (data->map[data->ply.y][data->ply.x + 1] == '1')
		return ;
	else if (data->map[data->ply.y][data->ply.x + 1] == 'C')
		ft_move_to_collec(data, 'R');
	else if ((data->map[data->ply.y][data->ply.x + 1] == 'E')
		&& (data->n_collected == data->n_collec))
		ft_move_to_exit(data, 'R');
	else
	{
		ft_exec_move(data, 'R');
		ft_print_moves(data);
	}
}
