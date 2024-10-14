/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:48:51 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/14 11:06:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int get_file_height(char *file)
{
    int fd = open(file, O_RDONLY);
    int height = 0;
    char *line;

    if (fd < 0)
    {
        ft_printf("Error: Could not open file.\n");
        return (-1);  // Error opening file
    }

    while ((line = get_next_line(fd)))
    {
        height++;
        free(line);  // Free line after
    }
    close(fd);
    return height;
}

//read the map into a 2 dimension array
char **read_map(char *file)
{
    int fd = open(file, O_RDONLY);
    char *line;
    char **map;
    int i = 0;
    int map_height;
    int map_width = 0;

    if (fd < 0)
    {
        ft_printf("Error: Could not open file.\n");
        return (NULL);
    }

    // use function to get the height of the map
    map_height = get_file_height(file);
    if (map_height <= 0)
    {
        ft_printf("Error: Invalid map height.\n");
        return (NULL);
    }

    // Allocate memory for the 2D array
    map = (char **)malloc(sizeof(char *) * (map_height + 1)); 

    // Read each line of the file and store in array
    while ((line = get_next_line(fd)))
    {
        if (i == 0)
            map_width = ft_strlen(line) - 1;  

        map[i] = ft_strdup(line);  // Copy the line to the map array
        free(line);  // Free the line after copy
        i++;
    }

    map[i] = NULL;  // Set the last element to NULL
    close(fd);

    // Print the map (for testing)
    ft_printf("Map size: %d x %d\n", map_width, map_height);
    for (int j = 0; j < map_height; j++)
        ft_printf("%s", map[j]); 

    return map;
}