# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 01:48:06 by scharuka          #+#    #+#              #
#    Updated: 2024/08/16 12:02:38 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

SRC_DIR = src/

FILES = minirt.c

SRC = $(addprefix $(SRC_DIR), $(FILES))

CC = cc

CPPFLAGS = -Wall -Wextra -Werror

HEADER = inc/miniRT.h

MLX_LIB = lib/minilibx-linux/libmlx.a

LIBFT_LIB = lib/libft_modified/libft.a

LIBVEC_LIB = lib/libvec/libvec.a

OBJ = $(SRC:.cpp=.o)

all:  $(NAME)

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
