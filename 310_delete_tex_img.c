/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   310_delete_tex_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:04:37 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 12:58:01 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ***************          WARNING:           ************** */
/* IT ISN'T NECESSARY TO DELETE IMAGES, mlx_terminate DO THAT */
/* BUT IF YOU WANT TO DELETE ONE BEFORE FINISH THE GAME,			*/
/* THEN YOU CAN USE mlx_delete_image FUNCTION 								*/

void	ft_delete_texture(t_bag *data)
{
	mlx_delete_texture(data->tex.bee_rg_1);
	mlx_delete_texture(data->tex.floor);
	mlx_delete_texture(data->tex.chest);
	mlx_delete_texture(data->tex.tree);
	mlx_delete_texture(data->tex.collec);
	mlx_delete_texture(data->tex.flowers);
	mlx_delete_texture(data->tex.pol);
	mlx_delete_texture(data->tex.exit);
	mlx_delete_texture(data->tex.hiv);
}
