/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   420_move_to_special.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:37:25 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/08/26 12:40:43 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************** */
/* ********          MOVING INTO/ COLLEC / EXIT         *********** */
/* **************************************************************** */

void	ft_move_to_collec(t_bag *d, char m)
{
	ft_exec_move(d, m);
	ft_print_moves(d);
	d->n_collected++;
	ft_printf("Hay %i flores sin polinizar\n", d->n_collec - d->n_collected);
	ft_printf("Has polinizado %i flores\n", d->n_collected);
	ft_polinized_flower(d);
	d->map[d->ply.y][d->ply.x] = '0';
}

void	ft_move_to_exit(t_bag *data, char m)
{
	ft_exec_move(data, m);
	ft_print_moves(data);
	ft_printf("\n");
	ft_printf("  *********************************************************\n");
	ft_printf("  ********   CONGRATS!!!  YOU WIN THE GAME !!!  ;)  *******\n");
	ft_printf("  ********          ( ANOTHER GAME ??? )            *******\n");
	ft_printf("  *********************************************************\n");
	ft_printf("\n");
	ft_full_hive(data);
	data->flag = 'n';
}
