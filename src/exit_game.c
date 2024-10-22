/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:36:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/22 19:38:37 by rda-cunh         ###   ########.fr       */
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
		free (map->grid[i]);
		map->grid[i] = NULL; //set pointer as NULL (avoid double free and increase safety)
		i++;
	}
	free (map->grid);
	map->grid = NULL; //set pointer as NULL (avoid double free and increase safety)
	free (map);
	map = NULL; //set pointer as NULL (avoid double free and increase safety)
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long->map); 
	//see what else must be set here, like cleaning sprites, mlx, mlx window, etc.
}
