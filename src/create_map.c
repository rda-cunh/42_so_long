/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:48:51 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/24 23:58:44 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//alocates memory for the map
t_map	*create_map(unsigned int width, unsigned int height)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = ft_calloc(height + 1, sizeof(char *));
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	map->height = height;
	map->width = width;
	map->players = 0;
	map->eggs = 0;
	map->exit = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->moves = 0;
	return (map);
}

//function to count the number os lines (height) in file
int	get_file_height(t_game *so_long, char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(so_long, "Error\nCould not open file.\n");
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

//read a line function used on read_map. also defines width variable
static void	read_map_line(t_game *so_long, int fd, unsigned int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		close (fd);
		exit_error(so_long, "Error\nCould not read map.\n");
	}
	so_long->map->grid[i] = ft_strdup(line);
	if (i == 0)
		so_long->map->width = ft_strlen(line) - 1;
	free(line);
}

//read the map into a 2 dimension array
void	read_map(t_game *so_long, char *file)
{
	int				fd;
	unsigned int	i;

	i = 0;
	so_long->map = create_map(0, get_file_height(so_long, file));
	if (!so_long->map)
		exit_error(so_long, "Error\nCould not read map.\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(so_long, "Error\nCould not open file.\n");
	while (i < so_long->map->height)
		read_map_line(so_long, fd, i++);
	close(fd);
}
