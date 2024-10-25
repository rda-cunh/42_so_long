/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:02:52 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/25 14:00:17 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	launch_mlx(t_game *game)
{
	game->display.mlx = mlx_init();
	if (!game->display.mlx)
		exit_error(game, "Error\nFailed to initialize MinilibX\n");
	game->display.win = mlx_new_window(game->display.mlx, game->map->width \
		* SIZE_TL, game->map->height * SIZE_TL, "So Long");
	if (!game->display.win)
		exit_error(game, "Error\nFailed to create window.\n");
}

//loading sprites into memory (evalute create a struct for them)
void	load_images(t_game *game)
{
	game->grass.img = mlx_xpm_file_to_image(game->display.mlx, GRASS_TL, \
					&game->grass.width, &game->grass.height);
	game->water.img = mlx_xpm_file_to_image(game->display.mlx, WATER_TL, \
					&game->water.width, &game->water.height);
	game->egg.img = mlx_xpm_file_to_image(game->display.mlx, EGG_TL, \
					&game->egg.width, &game->egg.height);
	game->exit.img = mlx_xpm_file_to_image(game->display.mlx, EXIT_TL, \
					&game->exit.width, &game->exit.height);
	game->player.img = mlx_xpm_file_to_image(game->display.mlx, PLAYER_TL, \
					&game->player.width, &game->player.height);
	if (!game->grass.img || !game->water.img || !game->egg.img || \
	!game->exit.img || !game->player.img)
		exit_error(game, "Error\nFailed to load images.\n");
}

//helper function for for render_map function above (norm u25)
static void	render_tile(t_game *game, unsigned int x, unsigned int y)
{
	void	*img;

	img = NULL;
	if (game->map->grid[y][x] == GRASS)
		img = game->grass.img;
	else if (game->map->grid[y][x] == WATER)
		img = game->water.img;
	else if (game->map->grid[y][x] == EGG)
		img = game->egg.img;
	else if (game->map->grid[y][x] == EXIT)
		img = game->exit.img;
	else if (game->map->grid[y][x] == PLAYER)
		img = game->player.img;
	if (img)
		mlx_put_image_to_window(game->display.mlx, game->display.win, \
		img, x * SIZE_TL, y * SIZE_TL);
}

//function to render the map
void	render_map(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
