# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 01:48:06 by scharuka          #+#    #+#              #
#    Updated: 2024/08/17 17:52:23 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

SRC_DIR = src/

FILES = minirt.c

SRC = $(addprefix $(SRC_DIR), $(FILES))

CC = cc

CPPFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux

HEADER = inc/minirt.h

MLX_LIB = lib/minilibx-linux/libmlx.a

LIBFT_LIB = lib/libft_modified/libft.a

LIBVEC_LIB = lib/libvec/libvec.a

OBJ = $(SRC:.cpp=.o)

all:  $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):$(OBJ) $(HEADER)
	@make -C lib/minilibx-linux/
	@make -C lib/libft_modified/
	@make -C lib/libvec/
	$(CC) $(CPPFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(LIBVEC_LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
