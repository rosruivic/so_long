/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:07:50 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 00:26:46 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_are_same_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_error_ext(t_bag *data, char *ext)
{
	if (ft_are_same_str(ext, data->ext))
		return (0);
	return (1);
}

void	ft_check_file(t_bag *data, char *pre_file)
{
	int	fd;
	int	len;
	int	ext;

	ext = 0;
	len = 0;
	while (pre_file[len])
		++len;
	if (len >= 5)
		ext = ft_error_ext(data, &pre_file[len - 4]);
	if (len < 5 || ext)
	{
		data->flag = 'n';
		perror("Error\n --- Nombre del archivo no válido.\n");
		exit(EXIT_FAILURE);
	}
	fd = open(pre_file, O_RDONLY);
	if (fd == -1)
	{
		data->flag = 'n';
		perror("Error\n --- Apertura de archivo imposible.\n");
		exit(EXIT_FAILURE);
	}
	data->f_name = ft_strdup(pre_file);
	close(fd);
}
