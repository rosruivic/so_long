/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:20:47 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/25 18:03:55 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*************************************************************************/
/******************         BUILDING THE MAP          ********************/
/*************************************************************************/

static void	ft_delete_nl(t_bag *data, int i)
{
	int		len;
	char	*tmp;

	len = ft_strlen(data->map[i]);
	if (data->map[i][len - 1] == '\n')
	{
		tmp = ft_substr(data->map[i], 0, len - 1);
		free(data->map[i]);
		data->map[i] = ft_strdup(tmp);
		free(tmp);
	}	
}

static void	ft_make_map(t_bag *data)
{
	int		i;
	int		fd;

	if (data->flag == 'n')
		return ;
	fd = open(data->f_name, O_RDONLY);
	data->map = ft_calloc(data->dim.y + 1, sizeof(char *));
	if (data->map == NULL)
	{
		close (fd);
		data->flag = 'n';
		return ;
	}
	i = 0;
	data->map[i] = get_next_line(fd);
	ft_delete_nl(data, i);
	while (++i < data->dim.y)
	{
		data->map[i] = get_next_line(fd);
		ft_delete_nl(data, i);
	}
	close (fd);
}

static void	ft_calc_map_dim(t_bag *data)
{
	int		fd;
	char	*tmp;

	fd = open(data->f_name, O_RDONLY);
	if (fd == -1)
	{
		ft_error_msg(data, ERROR_FD);
		return ;
	}
	tmp = get_next_line(fd);
	if (tmp == NULL)
	{
		ft_error_msg(data, ERROR_EMPTY_FILE);
		return ;
	}
	while (tmp != NULL)
	{
		data->dim.y++;
		data->deep = ft_strlen(tmp);
		if (tmp[data->deep - 1] == '\n')
			data->deep--;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

/**
 * @brief Check if the info of the file is playable.
 * 	Is playable if:
 * 		a) every line has the same len (without "\n").
 * 		b) minimum 3 rows && 3 lines.
 * 		c) if it's only 3 rows (/lines),
 * 			then it's necessary + than 2 + 6 = 8 lines (/rows) (P+E+C+X)
 * 
 * @param data 
 */
void	ft_get_map(t_bag *data)
{
	if (data->flag == 'n')
		return ;
	ft_calc_map_dim(data);
	ft_make_map(data);
}
