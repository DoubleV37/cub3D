# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 13:27:39 by jduval            #+#    #+#              #
#    Updated: 2023/05/11 09:10:02 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3D

MAKEFLAGS	+=	--no-print-directory

###############################################################################

LIBS 		=	ft mlx42 Xext X11 m z

LIBS_TARGET =	libft/libft.a			\
				MLX42/build/libmlx42.a	\

INCLUDES	=	libft/include 			\
				MLX42/include/MLX42		\
				/usr/lib				\

###############################################################################

BUILD_DIR 	= 	.obj

SRCS 		=

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

DEPS = $(OBJS:.o=.d)


###############################################################################

CC 			=	gcc

CFLAGS 		=	-Werror -Wextra -Wall -ggdb3

CPPFLAGS 	=	-MMD -MP $(addprefix -I,$(INCLUDES))

LDFLAGS		=	$(addprefix -L,$(dir $(LIBS_TARGET)))

LDLIBS		=	$(addprefix -l,$(LIBS))

DIRDUP 		= 	mkdir -p $(@D) 


###############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	@$(MAKE) -C $(dir $@)

$(BUILD_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS) test.mk

###############################################################################

clean:
	@${MAKE} -C libft/ clean
	@${MAKE} -C MLX42/build/ clean
	rm -rf .build
.PHONY:clean

fclean: clean 
	@${MAKE} -C libft/ fclean
	@${MAKE} -C MLX42/build/ clean
	rm -f ${NAME}
.PHONY: fclean

re: fclean all
.PHONY: re
