/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:53 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 13:04:57 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*****************************************************************/
/*************         VERIFYING THE MAP          ****************/
/*****************************************************************/

static void	ft_right_wall(t_bag *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (data->flag == 'n')
		return ;
	while (++j < data->dim.x)
	{
		if (data->map[0][j] != '1' || data->map[data->dim.y - 1][j] != '1')
		{
			ft_freedom(data->map);
			ft_error_msg(data, ERROR_NO_WALLS);
			return ;
		}
	}
	while (++i < data->dim.y)
	{
		if (data->map[i][0] != '1' || data->map[i][data->dim.x - 1] != '1')
		{
			ft_freedom(data->map);
			ft_error_msg(data, ERROR_NO_WALLS);
		}
	}
}

static void	ft_allowed_chr(t_bag *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->flag == 'n')
		return ;
	while (++i < data->dim.y - 1)
	{
		while (++j < data->dim.x - 1)
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != '0'
				&& data->map[i][j] != 'C'
				&& data->map[i][j] != 'E' && data->map[i][j] != '1')
			{
				ft_error_msg(data, ERROR_FORBIDDEN_CHAR);
				ft_freedom(data->map);
				return ;
			}
		}
		j = 0;
	}
}

static int	ft_is_not_square(t_bag *data)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[++i])
		if (len != ft_strlen(data->map[i]))
			return (1);
	data->dim.x = len;
	data->dim.y = i;
	return (0);
}

static void	ft_right_dim(t_bag *data)
{
	int	i;

	i = 0;
	if (data->flag == 'n')
		return ;
	if ((data->flag == 'n' || ft_is_not_square(data)
			|| data->dim.x < 3 || data->dim.y < 3)
		|| ((data->dim.x == 3 && data->dim.y < 5)
			|| (data->dim.y == 3 && data->dim.x < 5)))
	{
		ft_error_msg(data, ERROR_NO_SQUARE);
		ft_freedom(data->map);
	}
}

void	ft_check_map(t_bag *data)
{
	if (data->flag == 'n')
		return ;
	ft_right_dim(data);
	ft_allowed_chr(data);
	ft_right_wall(data);
	ft_loc_player(data);
	ft_loc_exit(data);
	ft_loc_collec(data);
	ft_right_path(data);
}
