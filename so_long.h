/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:04 by roruiz-v          #+#    #+#             */
/*   Updated: 2023/09/10 18:07:27 by roruiz-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# define P 64
# define SECONDS 0.03
# define ERROR_DUPLIC_PLAYER 1
# define ERROR_DUPLIC_EXIT 2
# define ERROR_NO_SQUARE 3
# define ERROR_NO_WALLS 4
# define ERROR_NO_PATH 5
# define ERROR_FORBIDDEN_CHAR 6
# define ERROR_NO_PLAYER 7
# define ERROR_NO_EXIT 8
# define ERROR_NO_COLLECTABLES 9
# define ERROR_FD 11
# define ERROR_EMPTY_FILE 12
//# include "memory-leaks/include/memory_leaks.h"

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_texture
{
	mlx_texture_t	*bee_rg_1;
	mlx_texture_t	*floor;
	mlx_texture_t	*chest;
	mlx_texture_t	*tree;
	mlx_texture_t	*collec;
	mlx_texture_t	*flowers;
	mlx_texture_t	*pol;
	mlx_texture_t	*enemy;
	mlx_texture_t	*exit;
	mlx_texture_t	*hiv;
}								t_texture;

typedef struct s_image
{
	mlx_image_t	*bee_r;
	mlx_image_t	*floor;
	mlx_image_t	*chest;
	mlx_image_t	*tree;
	mlx_image_t	*co;
	mlx_image_t	*flo;
	mlx_image_t	*pol;
	mlx_image_t	*en;
	mlx_image_t	*exi;
	mlx_image_t	*hiv;
	mlx_image_t	*counter;
}							t_image;

/**
 * @brief METADATA
 * 	mlx_t			*mlx;					// ventana del juego (y sus metadatos)
 *	t_texture	tex;					// texturas para las imágenes
 *	double		time;					// tiempo pasado desde el anterior frame (deltatime)
 *	int				frame;				// contador para pasar por los 4 frames de la animación
 *	int				direc;				// dirección del movimiento
 *	t_image		im;						// imágenes a partir de las texturas
 *	t_point		dim;					// dimensiones del mapa
 *	t_point		ply;					// coordenadas lógicas del jugador
 *	t_point		exi;					// coordenadas lógicas de la salida
 *	t_point		*col;					// coordenadas lógicas de los coleccionables
 *	int				n_collec;			// número de coleccionables
 *	int				n_collected;	// contador de coleccionables recolectados
 *	int				n_enemy;			// número de enemigos
 *	int				n_movs;				// número de movimientos
 *	char			*f_name;			// nombre del fichero .ber
 *	char			*ext;					// extensión solicitada ( = .ber)
 *	char			**map;				// mapa leído desde el fichero
 *	char			**twin;				// gemelo del mapa leído desde el fichero
 *	char			flag;					// bandera semáforo para continuar o terminar
 */
typedef struct s_bag
{
	mlx_t				*mlx;
	t_texture			tex;
	t_image				im;
	t_point				dim;
	t_point				ply;
	t_point				exi;
	t_point				*co;
	int					n_collec;
	int					n_collected;
	int					n_movs;
	char				*f_name;
	char				*ext;
	char				**map;
	char				**twin;
	int					deep;
	char				flag;
}						t_bag;

/* ************************************************************* */
/* ********   100 - CHECKING THE MAP FILE NAME    ************** */
/* ********    & READING THE MAP FROM THE FILE    ************** */
/* ************************************************************* */

/**
 * @brief Checks if the file has a valid name (*.ber) 
 * @param data 				The struct with the metadata.
 * @param pre_file 		The argv[1] parameter
 */
void	ft_check_file(t_bag *data, char *pre_file);

/**
 * @brief Captures the info of the file, using gnl. First reading allows
 * 				to check how many lines has the file and reserves with malloc.
 * 				Second reading deletes "\n" character at the end of line &
 * 				complete the rest of the map (each line = gnl).
 * 	(It had could be done with only one reading {strjoin + split}, yes).
 * @param data 				The struct with the metadata.
 */
void	ft_get_map(t_bag *data);

/* ************************************************************* */
/* ********   200 - CHECKING PLAYABILITY OF THE MAP    ********* */
/* ************************************************************* */

/**
 * @brief Verifies if the map is playable (it must be rectangular, with walls
 * 				perimeter, and a valid way between player, collectables & exit). 
 * @param data 				The struct with the metadata.
 */
void	ft_check_map(t_bag *data);

/**
 * @brief Find the player position & save it in its metadata location.
 * @param data 				The struct with the metadata.
 */
void	ft_loc_player(t_bag *data);			

/**
 * @brief Find the exit position & save it in its metadata location.
 * 
 * @param data 				The struct with the metadata.
 */
void	ft_loc_exit(t_bag *data);

/**
 * @brief Find the collectables position & save them in their 
 * 				metadata locations. 
 * @param data 				The struct with the metadata.
 */
void	ft_loc_collec(t_bag *data);

/**
 * @brief Checks, using flood_fill, if there is a valid way between player
 * 				& collectables & exit
 * @param data 
 */
void	ft_right_path(t_bag *data);

/* ************************************************************* */
/* ************   300 - PAINTING THE GAME WINDOW    ************ */
/* ************************************************************* */

int32_t	ft_paint_window(t_bag *data);
void	ft_delete_texture(t_bag *data);
void	ft_displ_imgs(t_bag *data);

/* ************************************************************* */
/* *************    400 -	PLAYING THE GAME        ************** */
/* ************************************************************* */

/**
 * @brief First of the '400' files: 
 * 	- Opens the game window & has the handler function.
 * 	- Calls the up/down/left/right functions.
 * 	- Loop the game.
 * 	- Terminate the game. 
 * @param data 
 */
void	ft_play_game(t_bag *data);
// static void	ft_hook(mlx_key_data_t keydata, void *param);

/**
 * @brief This 4 fts check if the move is possible
 * 				(& call the exec_move ft) 
 * @param data 
 */
void	ft_up(t_bag *data);
void	ft_down(t_bag *data);
void	ft_left(t_bag *data);
void	ft_right(t_bag *data);

/**
 * @brief This 3 fts execute the move of the player
 *				& increase de move counter (in the terminal)
 * @param data 
 * @param m 
 */
void	ft_exec_move(t_bag *data, char m);
void	ft_print_moves(t_bag *data);

/**
 * @brief This 2 fts do the necessary actions to move
 * 		into a special position (collectable / exit)
 * @param data 
 * @param m 
 */
void	ft_move_to_collec(t_bag *data, char m);
void	ft_move_to_exit(t_bag *data, char m);

void	ft_polinized_flower(t_bag *data);
void	ft_full_hive(t_bag *data);

/* ************************************************************* */
/* *************    800 -	ERROR MESSAGES          ************** */
/* ************************************************************* */

void	ft_error_msg(t_bag *data, int error_code);

/* ************************************************************* */
/* *************    900 -	GAME OVER				        ************** */
/* ************************************************************* */

void	ft_game_over(t_bag *data);

#endif
