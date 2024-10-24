/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:36:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/24 19:10:40 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (!map->grid)
		return ;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

void	clean_sprites(t_game *so_long)
{
	if (so_long->grass.img)
		mlx_destroy_image(so_long->display.mlx, so_long->grass.img);
	if (so_long->water.img)
		mlx_destroy_image(so_long->display.mlx, so_long->water.img);
	if (so_long->egg.img)
		mlx_destroy_image(so_long->display.mlx, so_long->egg.img);
	if (so_long->exit.img)
		mlx_destroy_image(so_long->display.mlx, so_long->exit.img);
	if (so_long->player.img)
		mlx_destroy_image(so_long->display.mlx, so_long->player.img);
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long->map);
	clean_sprites(so_long);
	if (so_long->display.win)
		mlx_destroy_window(so_long->display.mlx, so_long->display.win);
	if (so_long->display.mlx)
		mlx_destroy_display(so_long->display.mlx);
	free(so_long->display.mlx);  
}

//print error message and clean up
int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

//clean up and exit the game succesfully
int	end_game(t_game *so_long)
{
	clean_game(so_long);
	exit(EXIT_SUCCESS);
}
