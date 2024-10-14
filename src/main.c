/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:05:52 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/10 20:09:51 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void start_game(char *file)
{
	char	**map;
	int		i; 

	map = read_map(file);
	if (map = NULL)
	{
		ft_printf("Failed to read map.\n");
		return (1); 
	}

	//here i whant to do something simple with the map like print it

	//free the map after using it
	while (map[i] != NULL)
		free(map[i]);
	free (map); 
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("Invalid number of arguments.\n");
	start_game(argv[1]); // starting the game with the map file
	return (0);  
}

/*
//some code to test minilibX

//replace the pixel put function of the minilibX library for more efficient one
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//function to manipulate pixels and paint all pixels in one color (red)
void	fill_image_with_color(t_data *img, int width, int height, int color)
{
	int x;
	int y;

	y = 0; 
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++; 
		}
		y++;
	}
}

//hook configuration for when the user press ESC  
int	key_hook(int keycode, void *param)
{
	(void)param; 
	if (keycode == 65307) //keycode for ESC
		exit(0);
	return (0);
}

// my main to create a window, and image, paint all pixels red and put the image on window. Also closes window using cross or ESC
int main(void)
{
    void    *mlx;
    void    *mlx_win;
	t_data	img;

    mlx = mlx_init();
    if (!mlx)
        return (1);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	if (!mlx_win)
        return (1);
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
				&img.line_length, &img.endian);
	fill_image_with_color(&img, 1920, 1080, 0x00FF0000);
	my_mlx_pixel_put(&img, 960, 540, 0x00FF0000); //paint the center pixel in black
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, NULL);
	mlx_hook(mlx_win, 17, 0, mlx_win, NULL);  // 17 is the event for window close
	mlx_loop(mlx);
//	mlx_destroy_display(mlx);
//	free(mlx);
	return (0); 
}
*/