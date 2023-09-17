/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   220_loc_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:13:09 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/25 16:56:01 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*****************************************************************/
/*************          FINDING THE EXIT					****************/
/*****************************************************************/

static void	ft_finding_exit(t_bag *data, int i, int j, char *find)
{
	if (data->map[i][j] == 'E' && *find == 'y')
	{
		ft_error_msg(data, ERROR_DUPLIC_EXIT);
		ft_freedom(data->map);
		return ;
	}
	else if (data->map[i][j] == 'E' && *find == 'n')
	{
		*find = 'y';
		data->exi.y = i;
		data->exi.x = j;
	}
}

void	ft_loc_exit(t_bag *data)
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
			ft_finding_exit(data, i, j, &find);
		j = -1;
	}
	if (find == 'n')
	{
		ft_error_msg(data, ERROR_NO_EXIT);
		ft_freedom(data->map);
	}
}
