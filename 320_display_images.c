/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   320_display_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:02:26 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/09/17 17:53:05 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_displ_wall_floor(t_bag *d)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < d->dim.y)
	{
		while (++j < d->dim.x)
		{
			if (d->map[i][j] == '1')
			{
				mlx_image_to_window(d->mlx, d->im.floor, j * P, i * P);
				mlx_image_to_window(d->mlx, d->im.tree, j * P, i * P);
			}
			if (d->map[i][j] == '0' || d->map[i][j] == 'P'
				|| d->map[i][j] == 'C' || d->map[i][j] == 'E')
				mlx_image_to_window(d->mlx, d->im.floor, j * P, i * P);
		}
		j = -1;
	}
	mlx_image_to_window(d->mlx, d->im.chest, 1, 1);
}

static void	ft_displ_collec(t_bag *d)
{
	int	i;

	i = -1;
	while (++i < d->n_collec)
	{
		mlx_image_to_window(d->mlx, d->im.co, d->co[i].x * P, d->co[i].y * P);
		mlx_image_to_window(d->mlx, d->im.flo, d->co[i].x * P, d->co[i].y * P);
		mlx_image_to_window(d->mlx, d->im.pol, d->co[i].x * P, d->co[i].y * P);
		d->im.pol->instances[i].enabled = false;
	}	
}

static void	ft_displ_exit(t_bag *d)
{
	mlx_image_to_window(d->mlx, d->im.exi, d->exi.x * P, d->exi.y * P);
	mlx_image_to_window(d->mlx, d->im.hiv, d->exi.x * P, d->exi.y * P);
	d->im.hiv->instances[0].enabled = false;
}

static void	ft_displ_player(t_bag *d)
{
	mlx_image_to_window(d->mlx, d->im.bee_r, d->ply.x * P, d->ply.y * P);
}

/**
 * @brief DISPLAy:
 * 		'1'->wall / '0'->floor / 'P'->player / 'C'->collec
 * 
 * @param data 
 */
void	ft_displ_imgs(t_bag *data)
{
	ft_displ_wall_floor(data);
	ft_displ_collec(data);
	ft_displ_exit(data);
	ft_displ_player(data);
}
