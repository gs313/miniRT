# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 01:48:06 by scharuka          #+#    #+#              #
#    Updated: 2024/08/24 15:41:26 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

SRC_DIR = src/
FILES = minirt.c sphere.c camera.c hit.c color.c scene.c
SRC = $(addprefix $(SRC_DIR), $(FILES))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Ilib/MLX42/include
HEADER = inc/minirt.h

MLX_LIB = lib/MLX42/build/libmlx42.a
# MLX_LIB = lib/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

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
