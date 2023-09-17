# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roruiz-v <roruiz-v@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 13:12:22 by roruiz-v          #+#    #+#              #
#    Updated: 2023/08/26 20:05:52 by roruiz-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC		=	so_long.c \
			100_check_file.c \
			110_get_map.c \
			200_check_map.c \
			210_loc_player.c \
			220_loc_exit.c \
			230_loc_collec.c \
			250_right_path.c \
			300_paint_window.c \
			310_delete_tex_img.c \
			320_display_images.c \
			400_play_game.c \
			410_check_move.c \
			420_move_to_special.c \
			430_exec_move.c \
			435_display_moves.c \
			440_polin_exit.c \
			800_error_msg.c \
			900_game_over.c

OBJS	= $(SRC:.c=.o)
OFILES = $(addprefix obj/, $(OBJS))

NAMEB	=	so_long_bonus

SRCB		=	so_long_bonus.c \
			100_check_file_bonus.c \
			110_get_map_bonus.c \
			200_check_map_bonus.c \
			210_loc_player_bonus.c \
			220_loc_exit_bonus.c \
			230_loc_collec_bonus.c \
			240_loc_enemy_bonus.c \
			250_right_path_bonus.c \
			300_paint_window_bonus.c \
			310_delete_tex_img_bonus.c \
			320_display_images_bonus.c \
			400_play_game_bonus.c \
			410_check_move_bonus.c \
			420_move_to_special_bonus.c \
			430_exec_move_bonus.c \
			435_display_moves_bonus.c \
			440_polin_or_dead_bonus.c \
			800_error_msg_bonus.c \
			900_game_over_bonus.c

OBJSB	= $(SRCB:.c=.o)
OFILESB = $(addprefix objb/, $(OBJSB))

CC		= gcc

FLAGS	= -Wall -Werror -Wextra #-fsanitize=address

EXTRA	=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/roruiz-v/.brew/opt/glfw/lib/"

#LEAKS = memory-leaks/memory_leaks.a

LIBFT_PATH = libft/libft.a

MLX42_PATH = MLX42/libmlx42.a

all:	$(NAME)

bonus:	$(NAMEB)

#	We cannot call (LIBFT) or (MLX42) in (NAME) because it would be searching for the
#	".a" files before creating them, resulting in an error. We 1st create the rules to
#	compile both libft and MLX42, and then we compile the .a files of both libraries
#	with the apropiate flags and frameworks.

$(NAME): $(OFILES) $(LIBFT_PATH) $(MLX42_PATH)
		$(CC) $(FLAGS) $(EXTRA) $(OFILES) $(LIBFT_PATH) $(MLX42_PATH) -o $(NAME)
		clear
 		
$(NAMEB): $(OFILESB) $(LIBFT_PATH) $(MLX42_PATH)
		$(CC) $(FLAGS) $(EXTRA) $(OFILESB) $(LIBFT_PATH) $(MLX42_PATH) -o $(NAMEB)
		clear
		
$(OFILES): $(SRC)
		@mkdir -p obj/
		gcc -Wall -Wextra -Werror -c $(SRC)
		@mv *.o obj/

$(OFILESB): $(SRCB)
		@mkdir -p objb/
		gcc -Wall -Wextra -Werror -c $(SRCB)
		@mv *.o objb/

# If a debug with lldb is needed, do 'make' with this rule:
debug: $(LIBFT_PATH) $(MLX42_PATH)
		$(CC) $(FLAGS) $(EXTRA) $(SRC) $(LIBFT_PATH) $(MLX42_PATH) -o $(NAME) -g
		clear

clean:
		rm -rf obj objb
		make -C libft clean

fclean: clean
		@make fclean -C libft/
		@make fclean -C MLX42/
		@rm $(NAME) $(NAMEB)

re:	fclean all bonus

$(LIBFT_PATH):
		make -C libft all

$(MLX42_PATH):
		make -C MLX42 all



.PHONY: all clean fclean re bonus
