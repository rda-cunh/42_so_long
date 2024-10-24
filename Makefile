# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 23:59:04 by rda-cunh          #+#    #+#              #
#    Updated: 2024/10/24 23:31:42 by rda-cunh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
SRCS = $(SRC_DIR)/check_map.c $(SRC_DIR)/create_map.c $(SRC_DIR)/exit.c \
		$(SRC_DIR)/main.c $(SRC_DIR)/movement.c $(SRC_DIR)/render_map.c \
		$(SRC_DIR)/utils.c		 
OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -Imlx

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
