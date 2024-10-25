/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:32:31 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/25 13:42:33 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	clean_tiles(char **tiles, unsigned int height)
{
	unsigned int	i;

	i = 0;
	if (!tiles)
		return ;
	while (i < height)
	{
		free(tiles[i]);
		i++;
	}
	free(tiles);
}

void	check_paths(t_game *so_long)
{
	unsigned int	i;
	int				reach_exit;
	char			**tiles;

	i = 0;
	reach_exit = 0;
	tiles = ft_calloc(so_long->map->height + 1, sizeof(char *));
	if (!tiles)
		exit_error(so_long, "Error\nMemory allocation failed.");
	while (i < so_long->map->height)
	{
		tiles[i] = ft_strdup(so_long->map->grid[i]);
		if (!tiles[i])
		{
			clean_tiles(tiles, so_long->map->height);
			exit_error(so_long, "Error\nMemory allocation failed.");
		}
		i++;
	}
	reach_exit = flood_fill(so_long->map, (t_point){so_long->map->player.x, \
				so_long->map->player.y}, tiles);
	if (!reach_exit)
		exit_error(so_long, "Error\nMap has invalid path.\n");
	clean_tiles(tiles, so_long->map->height);
}

void	check_map(t_game *so_long)
{
	check_shape(so_long);
	check_walls(so_long);
	count_map_objects(so_long);
	verify_map_objects(so_long);
	check_paths(so_long);
}
