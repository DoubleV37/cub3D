# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:18:12 by jduval            #+#    #+#              #
#    Updated: 2023/07/10 08:18:19 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CFLAGS		:= -Wall -Werror -Wextra

CPPFLAGS	:= -MMD -MP -I ./include 

CC			:= gcc

DIRDUP		= mkdir -p $(@D)

###############################################################################

SRC_DIR		:= functions

BUILD_DIR	:= .build_libft

SRCS 		:=	libft/ft_bzero.c		\
				libft/ft_isdigit.c		\
				libft/ft_isalnum.c		\
				libft/ft_isascii.c		\
				libft/ft_isprint.c		\
				libft/ft_isspace.c		\
				libft/ft_strlen.c		\
				libft/ft_memset.c		\
				libft/ft_isalpha.c		\
				libft/ft_memcpy.c		\
				libft/ft_memmove.c		\
				libft/ft_strlcpy.c		\
				libft/ft_strlcat.c		\
				libft/ft_toupper.c		\
				libft/ft_tolower.c		\
				libft/ft_strchr.c		\
				libft/ft_strrchr.c		\
				libft/ft_strncmp.c		\
				libft/ft_memchr.c		\
				libft/ft_memcmp.c		\
				libft/ft_strnstr.c		\
				libft/ft_atoi.c			\
				libft/ft_calloc.c		\
				libft/ft_strdup.c		\
				libft/ft_substr.c		\
				libft/ft_strjoin.c		\
				libft/ft_strjoin_free.c \
				libft/ft_strtrim.c		\
				libft/ft_split_char.c 	\
				libft/ft_split_str.c 	\
				libft/ft_itoa.c			\
				libft/ft_strmapi.c		\
				libft/ft_striteri.c		\
				libft/ft_lstmap.c		\
				libft/ft_putchar_fd.c	\
				libft/ft_putstr_fd.c	\
				libft/ft_putendl_fd.c	\
				libft/ft_putnbr_fd.c	\
				libft/ft_lstnew.c		\
				libft/ft_lstadd_front.c	\
				libft/ft_lstsize.c		\
				libft/ft_lstlast.c		\
				libft/ft_lstadd_back.c	\
				libft/ft_lstdelone.c	\
				libft/ft_lstclear.c		\
				libft/ft_lstiter.c		\
				libft/ft_lstmap.c		\
				libft/ft_array_lengh.c	\
				libft/ft_atoi_base.c	\
				libft/ft_strcspn.c		\
				libft/ft_free_array.c	\
				libft/ft_strcmp.c		\
				libft/ft_strcpy.c		\
				\
				old_gnl/get_next_line.c			\
				old_gnl/get_next_line_utils.c 	\
				\
				new_gnl/gnl_v2.c				\
				\
				printf/ft_printf.c				\
				printf/ft_printf_utils.c		\
				printf/ft_nbrlen.c				\

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS		:= $(OBJS:.o=.d)

###############################################################################

all: $(NAME)
.PHONY: all

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

###############################################################################

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

fclean: clean
	rm -rf $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

###############################################################################
