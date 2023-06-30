# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 13:27:39 by jduval            #+#    #+#              #
#    Updated: 2023/06/30 14:58:14 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef BONUS
NAME 		=	cub3D
else
NAME 		=	cub3D_bonus
endif

MAKEFLAGS	+=	--no-print-directory

###############################################################################

LIBS 		=	ft mlx42 dl glfw pthread m

LIBS_TARGET =	libft/libft.a				\
				MLX42/build/libmlx42.a		\

INCLUDES	=	libft/include 				\
				MLX42/include/MLX42			\
				/usr/lib					\
ifndef BONUS
INCLUDES	+=	sources/mandatory/includes	\
else
INCLUDES	+=	sources/bonus/includes		\
endif

###############################################################################

ifndef BONUS
SRC_DIR		=	sources/mandatory
BUILD_DIR 	= 	.obj
SRCS 		=	main.c							\
				parsing/load_map.c 				\
				parsing/utils_map.c 			\
				parsing/map_verif.c				\
				parsing/content_verif.c			\
				parsing/map_get_info.c 			\
				parsing/verify.c 				\
				parsing/resize_texture.c		\
				input/key_functions.c			\
				movements/move_player.c			\
				movements/shift_player.c		\
				movements/rotate_player.c		\
				movements/wall_collision.c		\
				draw/draw_utils.c				\
				draw/draw_background.c			\
				draw/render_image.c				\
				initialization/init_images.c	\
				initialization/init_player.c	\
				raycasting/raycasting.c			\
				raycasting/raycasting_utils.c	\
				raycasting/result_ray.c			\
				raycasting/texturing.c
else
SRC_DIR		=	sources/bonus
BUILD_DIR 	= 	.obj_bonus
SRCS 		=	main_bonus.c								\
				parsing/load_map_bonus.c 					\
				parsing/utils_map_bonus.c 					\
				parsing/map_verif_bonus.c					\
				parsing/content_verif_bonus.c				\
				parsing/map_get_info_bonus.c 				\
				parsing/verify_bonus.c 						\
				parsing/resize_texture_bonus.c				\
				parsing/linked_list_door_bonus.c			\
				parsing/create_door_list_bonus.c			\
				input/key_functions_bonus.c					\
				movements/move_player_bonus.c				\
				movements/shift_player_bonus.c				\
				movements/rotate_player_bonus.c				\
				movements/wall_collision_bonus.c			\
				draw/draw_utils_bonus.c						\
				draw/draw_background_bonus.c				\
				draw/render_image_bonus.c					\
				draw/draw_player_bonus.c					\
				draw/draw_map_bonus.c						\
				draw/draw_line_bonus.c						\
				initialization/init_images_bonus.c			\
				initialization/init_parameters_bonus.c		\
				raycasting/raycasting_bonus.c				\
				raycasting/raycasting_utils_bonus.c			\
				raycasting/result_ray_bonus.c				\
				raycasting/texturing_bonus.c				\
				features/door_control_bonus.c				\
				features/door_utils_bonus.c
endif

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

OBJS 		:=	$(SRCS:%.c=$(BUILD_DIR)/%.o)

DEPS 		:=	$(OBJS:.o=.d)


###############################################################################

CC 			=	gcc

CFLAGS 		=	-Wextra -Wall -Werror -ggdb3
#-pedantic-errors -Wunused -Wunreachable-code

CPPFLAGS 	=	-MMD -MP $(addprefix -I,$(INCLUDES))

LDFLAGS		=	$(addprefix -L,$(dir $(LIBS_TARGET)))

LDLIBS		=	$(addprefix -l,$(LIBS))

DIRDUP 		= 	mkdir -p $(@D)


###############################################################################

all: $(NAME)
.PHONY:all

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	@$(MAKE) -C $(dir $@)

$(BUILD_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

###############################################################################

bonus:
	${MAKE} BONUS=1 all
.PHONY:bonus

clean:
	@${MAKE} -C libft/ clean
	@${MAKE} -C MLX42/build/ clean
	rm -rf .obj .obj_bonus
.PHONY:clean

fclean: clean
	@${MAKE} -C libft/ fclean
	@${MAKE} -C MLX42/build/ clean
	rm -f cub3D cub3D_bonus
.PHONY: fclean

re: fclean all
.PHONY: re
