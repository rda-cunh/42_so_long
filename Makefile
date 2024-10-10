NAME = so_long

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/create_map.c	
OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -Imlx

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a


MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

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
