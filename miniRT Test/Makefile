
NAME := MiniRT

SRC_DIR := src/
FILES := minirt.c \
		 camera.c \
		 sphere.c \
		 plane.c \
		 cylinder.c \
		 parser.c \
		 render.c \

SRC := $(addprefix $(SRC_DIR), $(FILES))

CC := cc
CFLAGS := -Wall -Wextra -Werror -I/usr/include -Ilib/MLX42/include

HEADER := inc/minirt.h

MLX_LIB := lib/MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
LIBFT_LIB := lib/libft_modified/libft.a
LIBVEC_LIB := lib/libvec/libvec.a

# Detect operating system
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	# for macOS
	GLFW_LIB := -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
	# for Linux
	GLFW_LIB := -lglfw -lGL -lm -lpthread -ldl -lX11
endif

OBJ := $(SRC:.c=.o)

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

.PHONY: all clean fclean re libmlx



# NAME	:= miniRT
# CFLAGS	:= -Wall -Wextra -Werror -O3
# LIBMLX	:= ./lib/MLX42
# LIBVEC  := ./lib/libvec

# HEADERS	:= -I/usr/include -I$(LIBMLX)/include -I$(LIBVEC)
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= $(shell find ./src -iname "*.c")
# OBJS	:= ${SRCS:.c=.o}

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# clean:
# 	@rm -rf $(OBJS)
# 	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	@rm -rf $(NAME)

# re: clean all

# .PHONY: all clean fclean re libmlx