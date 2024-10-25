/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:29:30 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/25 12:07:47 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//verifies map filename
int	check_filename(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len <= 4 || !ft_strncmp((file + len - 4), ".ber", 4) != 0)
		return (0);
	else
		return (1);
}

//checks if two poins (x1, y1) and (x2,y2) are the same
int	is_same_point(t_point a, t_point b)
{
	return (a.x == b.x && a.y == b.y);
}

//gets the tile object (char) at a specific map point
char	get_object(t_game *so_long, t_point point)
{
	return (so_long->map->grid[point.y][point.x]);
}

//print map size and map grid
void	print_map(t_game *so_long)
{
	unsigned int	j;

	j = 0;
	ft_printf("Map size: %d x %d\n", so_long->map->width, so_long->map->height);
	while (j < so_long->map->height)
	{
		ft_printf("%s", so_long->map->grid[j]);
		j++;
	}
	ft_printf("\n");
}

//flood fill funtion allows to check for path for colectibles and exit
int	flood_fill(t_map *map, t_point curr, char **path)
{
	static unsigned int	eggs = 0;
	static int			exit = 0;

	if (curr.x >= map->width || curr.y >= map->height || \
		path[curr.y][curr.x] == WATER)
		return (0);
	if (path[curr.y][curr.x] == EGG)
		eggs++;
	else if (path[curr.y][curr.x] == EXIT)
		exit = 1;
	path[curr.y][curr.x] = WATER;
	flood_fill(map, (t_point){curr.x + 1, curr.y}, path);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, path);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, path);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, path);
	return (eggs == (unsigned int)map->eggs && exit == 1);
}
