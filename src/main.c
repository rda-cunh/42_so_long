/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:05:52 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/08 19:30:48 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, void *param)
{
	(void)param; 
	if (keycode == 65307) //keycode for ESC
		exit(0);
	return (0);
}

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
	my_mlx_pixel_put(&img, 960, 540, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, NULL);
	mlx_hook(mlx_win, 17, 0, mlx_win, NULL);  // 17 is the event for window close
	mlx_loop(mlx);
//	mlx_destroy_display(mlx);
//	free(mlx);
	return (0); 
}