




%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx-linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx-linux -lXext -lX11 -lm -lz -o $(NAME)





