# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 21:47:41 by scharuka          #+#    #+#              #
#    Updated: 2024/08/28 17:11:51 by ookamonu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#SRCS := $(shell find . -name '*.c')
SRCS =  ft_isdigit.c\
		ft_memcpy.c\
		ft_split.c\
		ft_strlen.c\
		ft_atof.c \
		ft_tolower.c\
			ft_atoi.c         ft_isprint.c      ft_memmove.c      ft_strchr.c       ft_strmapi.c      ft_toupper.c \
			ft_bzero.c        ft_itoa.c       ft_memset.c       ft_strdup.c       ft_strncmp.c \
			ft_calloc.c       ft_putchar_fd.c   ft_striteri.c     ft_strnstr.c \
			ft_isalnum.c      ft_putendl_fd.c   ft_strjoin.c      ft_strrchr.c \
			ft_isalpha.c      ft_memchr.c       ft_putnbr_fd.c    ft_strlcat.c      ft_strtrim.c \
			ft_isascii.c      ft_memcmp.c       ft_putstr_fd.c    ft_strlcpy.c      ft_substr.c \
		ft_lstiter.c\
		 ft_lstlast.c\
		 ft_lstmap.c\
		 ft_lstnew.c\
		 ft_lstsize.c\
		 ft_lstadd_back.c\
		 ft_lstadd_front.c\
		 ft_lstclear.c\
		 ft_lstdelone.c\
		 get_next_line.c\
		 get_next_line_utils.c\
		

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
