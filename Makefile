NAME = so_long

SRC_DIR = SRC_DIR
SRCS = $(SRC_DIR)/main.c	
OBJS = $(SRCS:.c=.o)

INCLUDES = -I/usr/include -Imlx

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

MINILIBX_DIR = ./libx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(LIBFT): 

	$(MAKE) -C $(LIBFTDIR)

$(MINILIBX)
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
