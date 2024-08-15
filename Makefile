# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 01:48:06 by scharuka          #+#    #+#              #
#    Updated: 2024/08/16 01:54:36 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MiniRT

SRC_DIR = src/

SRC = main.c

CC = cc

CPPFLAGS = -Wall -Wextra -Werror

HEADER = inc/miniRT.h

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
