# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 01:48:06 by scharuka          #+#    #+#              #
#    Updated: 2024/08/16 11:25:10 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

SRC_DIR = src/

SRC = main.c

CC = cc

CPPFLAGS = -Wall -Wextra -Werror

HEADER = inc/miniRT.h

MLX_LIB = minilibx-linux/libmlx.a

LIBFT_LIB = libft_modified/libft.a

LIBVEC_LIB = libvec/libvec.a

OBJ = $(SRC:.cpp=.o)

all: lib $(NAME)

lib:
	@make -C minilibx-linux/
	@make -C libft_modif/
	@make -C libvec/
	
$(NAME):$(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(LIBVEC_LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
