# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 10:24:19 by scharuka          #+#    #+#              #
#    Updated: 2024/08/16 10:59:37 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a

SRCS = vec_init.c vec_add.c vec_len.c vec_sub.c vec_norm.c vec_prodict.c vec_scale.c

OBJS := $(SRCS:.c=.o)

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
bonus: $(NAME)
		ar -rcs $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
all: bonus
re: fclean all