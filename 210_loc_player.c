/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   210_loc_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:13:04 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/25 16:44:50 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*****************************************************************/
/*************           FINDING PLAYER           ****************/
/*****************************************************************/

static void	ft_finding_player(t_bag *data, int i, int j, char *find)
{
	if (data->map[i][j] == 'P' && *find == 'y')
	{
		ft_error_msg(data, ERROR_DUPLIC_PLAYER);
		ft_freedom(data->map);
		return ;
	}
	else if (data->map[i][j] == 'P' && *find == 'n')
	{
		*find = 'y';
		data->ply.y = i;
		data->ply.x = j;
	}
}

void	ft_loc_player(t_bag *data)
{
	int		i;
	int		j;
	char	find;

	if (data->flag == 'n')
		return ;
	i = -1;
	j = -1;
	find = 'n';
	while (++i < data->dim.y)
	{
		while (++j < data->dim.x)
			ft_finding_player(data, i, j, &find);
		j = -1;
	}
	if (find == 'n')
	{
		ft_error_msg(data, ERROR_NO_PLAYER);
		ft_freedom(data->map);
	}
}
