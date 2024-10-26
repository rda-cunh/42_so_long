# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 23:59:04 by rda-cunh          #+#    #+#              #
#    Updated: 2024/10/26 18:19:25 by rda-cunh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
SRCS = $(SRC_DIR)/check_map.c $(SRC_DIR)/check_map1.c $(SRC_DIR)/create_map.c \
		$(SRC_DIR)/exit.c $(SRC_DIR)/main.c $(SRC_DIR)/movement.c \
		$(SRC_DIR)/render_map.c $(SRC_DIR)/utils.c		 
OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
