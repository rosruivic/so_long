/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:11:41 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/09/07 18:55:13 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_leaks(void)
{
	system("leaks -q so_long");
}

static void	ft_init(t_bag *data)
{
	data->mlx = NULL;
	data->dim.x = 0;
	data->dim.y = 0;
	data->ply.x = -1;
	data->ply.y = -1;
	data->exi.x = -1;
	data->exi.y = -1;
	data->co = NULL;
	data->n_collec = 0;
	data->n_collected = 0;
	data->n_movs = 0;
	data->f_name = NULL;
	data->ext = ".ber";
	data->map = NULL;
	data->twin = NULL;
	data->deep = 0;
	data->flag = 'y';
}

/**
 * @brief 
 * 	atexit(ft_leaks);
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	t_bag	data;

	if (argc != 2)
	{
		perror("Error\n Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&data);
	ft_check_file(&data, argv[1]);
	ft_get_map(&data);
	ft_check_map(&data);
	ft_paint_window(&data);
	ft_play_game(&data);
	ft_game_over(&data);
	atexit(ft_leaks);
	return (0);
}
