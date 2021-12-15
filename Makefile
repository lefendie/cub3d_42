# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 11:00:29 by lefendie          #+#    #+#              #
#    Updated: 2021/10/23 15:24:52 by lefendie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

MAIN := main.c

OBJ_MAIN := $(MAIN:.c=.o)

SRC		:=	parser/extract_data.c parser/map_analyzer.c parser/map_check_corner.c parser/map_checker.c parser/player_set.c parser/parser.c parser/color.c parser/map_alloc.c\
					raycast/angle_analyzer.c raycast/collision.c raycast/extract_pos.c raycast/init_pos.c raycast/pos_analyzer.c raycast/ray_cast.c\
					error/debug_func.c error/error_handler.c\
					process/initializer.c process/initializer2.c process/process.c\
					other/free_malloc.c other/free_malloc2.c other/get_next_line.c other/setter.c other/tools.c other/little_check.c\
					input/input_listener.c input/mouse_controller.c input/player_motion.c input/player_viewing.c\
					image/build_slice.c image/fill_cell.c image/print_image.c image/slice_data.c

OBJ		:= $(SRC:.c=.o)

OBJ_WITH_MAIN:= $(OBJ) ${OBJ_MAIN}

MAIN_BONUS := bonus/main_bonus.c

OBJ_MAIN_BONUS := $(MAIN_BONUS:.c=.o)

SRC_BONUS 	:=	bonus/process/initializer_bonus.c bonus/process/process_bonus.c\
								bonus/input/input_listener_bonus.c bonus/input/mouse_controller_bonus.c bonus/input/player_motion_bonus.c\
								bonus/other/door_checker_bonus.c bonus/other/door_handler_bonus.c bonus/other/free_malloc_bonus.c bonus/other/tools_bonus.c bonus/other/free_malloc2_bonus.c\
								bonus/parser/extract_data_bonus.c bonus/parser/map_analyzer_bonus.c bonus/parser/map_checker_bonus.c bonus/parser/parser_bonus.c bonus/parser/map_alloc_bonus.c\
								bonus/raycast/collision_bonus.c bonus/raycast/extract_line_bonus.c bonus/raycast/extract_pos_bonus.c bonus/raycast/pos_analyzer_bonus.c bonus/raycast/ray_cast_bonus.c\
								bonus/image/build_slice_bonus.c bonus/image/build_slice_door_bonus.c bonus/image/fill_cell_bonus.c bonus/image/print_image_bonus.c

								
OBJ_BONUS		:= $(SRC_BONUS:.c=.o) ${OBJ} 

OBJ_BONUS_WITH_MAIN		:= $(OBJ_BONUS) ${OBJ_MAIN_BONUS} 

%.o: %.c; ${CC} ${CFLAGS} -o $@ -c $<

RM	= /bin/rm -rf

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -Ilibft -Iinclude -Imlx_linux -g3

LIB = -Llibft -lft -Lmlx_linux -lmlx -lXext -lX11 -lm -lbsd 

%_bonus.o: CFLAGS += -O3 -Ibonus/include

${NAME}: ${OBJ_WITH_MAIN}
	make -s -C ./libft
	make -s -C ./mlx_linux
	${CC} ${OBJ_WITH_MAIN} -o ${NAME} ${LIB}

all: ${NAME} 

bonus: ${OBJ_BONUS_WITH_MAIN}
	make -s -C ./libft
	make -s -C ./mlx_linux
	${CC} ${OBJ_BONUS_WITH_MAIN} -o ${NAME} ${LIB}

clean:
	${RM} ${OBJ_WITH_MAIN} ${OBJ_BONUS_WITH_MAIN} libft/libft.a mlx_linux/libmlx.a

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: re clean fclean all bonus
