/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:48:51 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/15 23:44:18 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_file_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
    height = 0;
    if (fd < 0)
    {
        ft_printf("Error: Could not open file.\n");
        return (-1);
    }
    while ((line = get_next_line(fd)))
    {
        height++;
        free(line);  // Free line after reading
    }
    close(fd);
    return (height);
}

//read the map into a 2 dimension array
char	**read_map(char *file, int *map_height)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;
	int		j;
	int		map_width;

	fd = open(file, O_RDONLY);
    i = 0;
    j = 0; 
    map_width = 0;
    if (fd < 0)
    {
        ft_printf("Error: Could not open file.\n");
        return (NULL);
    }
    *map_height = get_file_height(file);
    if (*map_height <= 0)
    {
        ft_printf("Error: Invalid map height.\n");
        return (NULL);
    }
    // Allocate memory for the 2D array
    map = (char **)malloc(sizeof(char *) * (*map_height + 1));
	if (!map)
	{
		close(fd);
		ft_printf("Error: Memory allocation failed for map.\n");
		return (NULL);
	}

    // Read each line of the file and store in array
    while (i < *map_height && (line = get_next_line(fd)))
    {
        if (i == 0)
            map_width = ft_strlen(line) - 1;  
        map[i] = ft_strdup(line);  // Copy the line to the map array~
		if (!map[i])
		{
			ft_printf("Error: Memory allocation failed for line %d.\n", i);
			clean_map(map, i);
			close (fd);
			return (NULL); 
		}
        free(line);  // Free the line after copy
        i++;
    }
    map[i] = NULL;  // Set the last element to NULL
    close(fd);

    // Print the map 
    ft_printf("Map size: %d x %d\n", map_width, *map_height);
    while (j < *map_height)
    {
        ft_printf("%s", map[j]);
        j++;  
    }
    ft_printf("\n");
    return (map);
}