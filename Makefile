# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 01:48:06 by scharuka          #+#    #+#              #
#    Updated: 2024/08/19 18:26:08 by ookamonu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = MiniRT

# SRC_DIR = src/

# FILES = minirt.c

# SRC = $(addprefix $(SRC_DIR), $(FILES))

# CC = cc

# CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux

# HEADER = inc/minirt.h

# MLX_LIB = lib/minilibx-linux/libmlx.a

# LIBFT_LIB = lib/libft_modified/libft.a

# LIBVEC_LIB = lib/libvec/libvec.a

# OBJ = $(SRC:.c=.o)

# all:  $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME):$(OBJ) $(HEADER)
# 	@make -C lib/minilibx-linux/
# 	@make -C lib/libft_modified/
# 	@make -C lib/libvec/
# 	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(LIBVEC_LIB) -o $(NAME)

# clean:
# 	rm -rf $(OBJ)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean $(NAME)

# .PHONY: all clean fclean re


NAME = MiniRT

SRC_DIR = src/
FILES = minirt.c
SRC = $(addprefix $(SRC_DIR), $(FILES))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Ilib/MLX42/include
HEADER = inc/minirt.h

MLX_LIB = lib/MLX42/build/libmlx42.a
LIBFT_LIB = lib/libft_modified/libft.a
LIBVEC_LIB = lib/libvec/libvec.a

# for mac
# GLFW_LIB = -lglfw -framework Cocoa -framework OpenGL -framework IOKit
# for linux
# GLFW_LIB = -lglfw -lGL -lm -lpthread -ldl -lX11

# Detect operating system
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	# for macOS
	GLFW_LIB = -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
	# for Linux
	GLFW_LIB = -lglfw -lGL -lm -lpthread -ldl -lX11
endif

OBJ = $(SRC:.c=.o)

all: libmlx $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	@make -s -C lib/libft_modified/
	@make -s -C lib/libvec/
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(LIBVEC_LIB) $(GLFW_LIB) -o $(NAME)

libmlx:
	@cmake -B lib/MLX42/build lib/MLX42 && cmake --build lib/MLX42/build -j4

clean:
	rm -rf $(OBJ)
	rm -rf lib/MLX42/build
	@make -s -C lib/libft_modified fclean
	@make -s -C lib/libvec fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
