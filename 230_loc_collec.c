/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   230_loc_collec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:13:13 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/25 17:13:33 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*****************************************************************/
/*************      FINDING THE COLLECTABLES      ****************/
/*****************************************************************/

static void	ft_finding_collec(t_bag *data)
{
	int	i;
	int	j;
	int	col;	

	i = -1;
	j = -1;
	col = 0;
	while (++i < data->dim.y)
	{
		while (++j < data->dim.x)
		{
			if (data->map[i][j] == 'C')
			{
				data->co[col].y = i;
				data->co[col].x = j;
				col++;
			}
		}
		j = -1;
	}
}

static void	ft_counting_collec(t_bag *data)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < data->dim.y)
	{
		while (++j < data->dim.x)
		{
			if (data->map[i][j] == 'C')
				data->n_collec++;
		}
		j = -1;
	}
}

void	ft_loc_collec(t_bag *data)
{
	if (data->flag == 'n')
		return ;
	ft_counting_collec(data);
	if (data->n_collec == 0)
	{
		ft_error_msg(data, ERROR_NO_COLLECTABLES);
		ft_freedom(data->map);
		return ;
	}
	data->co = malloc(data->n_collec * sizeof(t_point));
	if (!data->co)
	{
		data->flag = 'n';
		ft_freedom(data->map);
		return ;
	}
	ft_finding_collec(data);
}	
