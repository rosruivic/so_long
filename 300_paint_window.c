/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   300_paint_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:41:01 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 12:43:05 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Load the image files (png)
 * 
 * @param data 
 */
static void	ft_load_tex(t_bag *data)
{
	data->tex.bee_rg_1 = mlx_load_png("./textures/Bee_R_1.png");
	data->tex.floor = mlx_load_png("./textures/grass.png");
	data->tex.chest = mlx_load_png("./textures/chest_closed.png");
	data->tex.tree = mlx_load_png("./textures/tree.png");
	data->tex.collec = mlx_load_png("./textures/collec.png");
	data->tex.flowers = mlx_load_png("./textures/flowers.png");
	data->tex.pol = mlx_load_png("./textures/flower_ok.png");
	data->tex.exit = mlx_load_png("./textures/hive_empty.png");
	data->tex.hiv = mlx_load_png("./textures/hive_full.png");
}

/**
 * @brief Converts textures into displayable images
 * 
 * @param data 
 */
static void	ft_conv_tex_to_img(t_bag *data)
{
	data->im.bee_r = mlx_texture_to_image(data->mlx, data->tex.bee_rg_1);
	data->im.floor = mlx_texture_to_image(data->mlx, data->tex.floor);
	data->im.chest = mlx_texture_to_image(data->mlx, data->tex.chest);
	data->im.tree = mlx_texture_to_image(data->mlx, data->tex.tree);
	data->im.co = mlx_texture_to_image(data->mlx, data->tex.collec);
	data->im.flo = mlx_texture_to_image(data->mlx, data->tex.flowers);
	data->im.pol = mlx_texture_to_image(data->mlx, data->tex.pol);
	data->im.exi = mlx_texture_to_image(data->mlx, data->tex.exit);
	data->im.hiv = mlx_texture_to_image(data->mlx, data->tex.hiv);
}

/**
 * @brief START GAME WINDOw:
 * If mlx_init() fails to set up the connection to the graphical system,
 * it will return NULL; otherwise a non-null pointer is returned as a
 * handle for the window.
 * 		# px(width) x # px(height), nombre_ventana, redim
 * @param data 
 */
static void	ft_create_playwindow(t_bag *data)
{
	data->mlx = mlx_init(data->dim.x * P, data->dim.y * P, "BeeP", false);
	if (!data->mlx)
	{
		data->flag = 'n';
		exit(EXIT_FAILURE);
	}	
}

int32_t	ft_paint_window(t_bag *data)
{
	if (data->flag == 'n')
		return (EXIT_FAILURE);
	ft_create_playwindow(data);
	ft_load_tex(data);
	ft_conv_tex_to_img(data);
	ft_delete_texture(data);
	ft_displ_imgs(data);
	return (EXIT_SUCCESS);
}
