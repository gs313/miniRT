# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 01:48:06 by scharuka          #+#    #+#              #
#    Updated: 2024/08/19 01:55:17 by ookamonu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

SRC_DIR = src/

FILES = minirt.c

SRC = $(addprefix $(SRC_DIR), $(FILES))

CC = cc

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux

HEADER = inc/minirt.h

MLX_LIB = lib/minilibx-linux/libmlx.a

LIBFT_LIB = lib/libft_modified/libft.a

LIBVEC_LIB = lib/libvec/libvec.a

OBJ = $(SRC:.c=.o)

all:  $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):$(OBJ) $(HEADER)
	@make -C lib/minilibx-linux/
	@make -C lib/libft_modified/
	@make -C lib/libvec/
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(LIBVEC_LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
