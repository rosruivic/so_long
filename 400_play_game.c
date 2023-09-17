/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   400_play_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:59 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 13:02:32 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************** */
/* ****************       PLAYING THE GAME        ***************** */
/* ****************     -	HANDLER	FUNCTION -      ***************** */
/* **************************************************************** */

static void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_bag	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if ((data->map[data->ply.y][data->ply.x] != 'E')
		|| (data->map[data->ply.y][data->ply.x] == 'E'
			&& data->n_collected < data->n_collec))
	{		
		if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
			ft_up(data);
		if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
			ft_down(data);
		if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
			ft_left(data);
		if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
			ft_right(data);
	}
}

/**
 * @brief 
 * 	'mlx_terminate' destroys & cleans up all images & mlx resources
 * 
 * @param data 
 */
void	ft_play_game(t_bag *data)
{
	if (data->flag == 'n')
		return ;
	mlx_key_hook(data->mlx, &ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	ft_freedom(data->map);
	free(data->co);
}
