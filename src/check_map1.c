/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:32:31 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/24 23:07:18 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//shape verification (rectangle) is missing 
void	check_shape(t_game *so_long)
{
	unsigned int	i;

	i = 0;
	while (i < so_long->map.height)
	{
		if (ft_srtlen(so_long->map->grid[i]) != so_long->map->width)
			return (0);
		i++;
	}
	return (1);
}

//function that verifies the border columns and then border lines
void	check_walls(t_game *so_long)
{
	unsigned int	i;

	i = 0;
	while (i < so_long->map->height)
	{
		if (so_long->map->grid[i][0] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
			on the first column\n");
		else if (so_long->map->grid[i][so_long->map->width - 1] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
			on the last column\n");
		i++;
	}
	i = 0;
	while (i < so_long->map->width)
	{
		if (so_long->map->grid[0][i] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
			on the first line\n");
		else if (so_long->map->grid[so_long->map->height - 1][i] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
			on the last line\n");
		i++;
	}
}

static void	process_map_cells(t_game *so_long, char cell, unsigned int x, \
		unsigned int y)
{
	if (!ft_strchr(TILES, so_long->map->grid[y][x]))
		exit_error(so_long, "Error\nInvalid Map. There's a map \
		object missing\n");
	else if (so_long->map->grid[y][x] == PLAYER)
	{
		so_long->map->players++;
		so_long->map->player.x = x;
		so_long->map->player.y = y;
		so_long->curr = (t_point){x, y};
		so_long->next = so_long->curr;
	}
	else if (so_long->map->grid[y][x] == EGG)
		so_long->map->eggs++;
	else if (so_long->map->grid[y][x] == EXIT)
		so_long->map->exit++;
}

void	count_map_objects(t_game *so_long)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < so_long->map->height)
	{
		x = 0;
		while (x < so_long->map->width)
		{
			process_map_cells(so_long, so_long->map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	verify_map_objects(t_game *so_long)
{
	if (so_long->map->eggs == 0)
		exit_error(so_long, "Error\nInvalid Map. There's no eggs.\n");
	else if (so_long->map->exit != 1)
		exit_error(so_long, "Error\nInvalid Map. There's no exit or more \
		than one exit.\n");
	else if (so_long->map->players != 1)
		exit_error(so_long, "Error\nInvalid Map. I'm only a sigle player \
		game because my programer is lazy.\n");
}
