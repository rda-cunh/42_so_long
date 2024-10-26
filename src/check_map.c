/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:06:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/26 00:14:16 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//checks minimum size and if map is rectangular
void	check_shape(t_game *so_long)
{
	unsigned int	i;
	size_t			line_length;

	if (so_long->map->height < 3 || so_long->map->width < 3)
		exit_error(so_long, "Error\nMap is too small.\n");
	i = 0;
	while (i < so_long->map->height)
	{
		line_length = ft_strlen(so_long->map->grid[i]);
		if (so_long->map->grid[i][line_length - 1] == '\n')
			line_length--;
		if (line_length != so_long->map->width)
			exit_error(so_long, "Error\nInvalid Map. The map is not \
rectangular.\n");
		i++;
	}
}

//verifies the border columns and then border lines for water/walls
void	check_walls(t_game *so_long)
{
	unsigned int	i;

	i = 0;
	while (i < so_long->map->height)
	{
		if (so_long->map->grid[i][0] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
on the first column.\n");
		else if (so_long->map->grid[i][so_long->map->width - 1] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
on the last column.\n");
		i++;
	}
	i = 0;
	while (i < so_long->map->width)
	{
		if (so_long->map->grid[0][i] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
on the first line.\n");
		else if (so_long->map->grid[so_long->map->height - 1][i] != WATER)
			exit_error(so_long, "Error\nInvalid Map. There's a wall missing \
on the last line.\n");
		i++;
	}
}

//static function used in count_map_objetct (norm u25)
static void	process_map_cells(t_game *so_long, unsigned int x, unsigned int y)
{
	if (!ft_strchr(TILES, so_long->map->grid[y][x]))
		exit_error(so_long, "Error\nInvalid Map. There's a map \
object missing.\n");
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

//count the number of objects and saves player position
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
			process_map_cells(so_long, x, y);
			x++;
		}
		y++;
	}
}

//verify if the number of objects in the map is correct
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
