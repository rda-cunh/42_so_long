/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:32:31 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/27 22:54:56 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//static in check paths to clean the map copy in case of error (norm u25)
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

//helper function to allocate and duplicate map grid (norm u25)
static char	**duplicate_map(t_game *so_long)
{
	unsigned int	i;
	char			**tiles;

	tiles = ft_calloc(so_long->map->height + 1, sizeof(char *));
	if (!tiles)
		exit_error(so_long, "Error\nMemory allocation failed.");
	i = 0;
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
	return (tiles);
}

// Check if all paths are reachable
void	check_paths(t_game *so_long)
{
	char	**tiles;
	int		reach_exit;

	tiles = duplicate_map(so_long);
	reach_exit = flood_fill(so_long->map, (t_point){so_long->map->player.x, \
	so_long->map->player.y}, tiles);
	if (!reach_exit)
	{
		clean_tiles(tiles, so_long->map->height);
		exit_error(so_long, "Error\nMap has invalid path.\n");
	}
	clean_tiles(tiles, so_long->map->height);
}

//run a set of functions defined to check map requirements
void	check_map(t_game *so_long)
{
	check_shape(so_long);
	check_walls(so_long);
	count_map_objects(so_long);
	verify_map_objects(so_long);
	check_paths(so_long);
}
