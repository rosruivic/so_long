/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   800_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:36:08 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 01:01:37 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(t_bag *data, int error_code)
{
	if (error_code == 1)
		ft_putstr_fd("Error\n --- Find more than one player\n", 2);
	if (error_code == 2)
		ft_putstr_fd("Error\n --- Find more than one exit\n", 2);
	if (error_code == 3)
		ft_putstr_fd("Error\n --- Your map doesn't have valid dimensions\n", 2);
	if (error_code == 4)
		ft_putstr_fd("Error\n --- Your map is not round of walls\n", 2);
	if (error_code == 5)
		ft_putstr_fd("Error\n --- Your map has not a valid path\n", 2);
	if (error_code == 6)
		ft_putstr_fd("Error\n --- Your map has forbidden characters\n", 2);
	if (error_code == 7)
		ft_putstr_fd("Error\n --- Your map has not a player\n", 2);
	if (error_code == 8)
		ft_putstr_fd("Error\n --- Your map has not an exit\n", 2);
	if (error_code == 9)
		ft_putstr_fd("Error\n --- Your map has not collectables at all\n", 2);
	if (error_code == 11)
		ft_putstr_fd("Error\n --- NO VALID FILE DESCRIPTOR\n", 2);
	if (error_code == 12)
		ft_putstr_fd("Error\n --- VOID FILE\n", 2);
	data->flag = 'n';
}
