/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:36:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/20 23:25:03 by rda-cunh         ###   ########.fr       */
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
