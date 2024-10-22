/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:32:31 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/21 23:59:18 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    check_line_walls(t_game *so_long)
{
    unsigned int i;

    i = 0; 
    while (i < so_long->map.height)
    {
        if (so_long->map.grid[i][0] != WATER)
        {
            ft_printf("Error\nInvalid Map. There's a wall missing on the first line\n");
            exit(1);
        }
        else if (so_long->map.grid[i][so_long->map.height - 1] != WATER)
        {
            ft_printf("Error\nInvalid Map. There's a wall missing on the last line\n");
            exit(1);            
        }
        i++;
    }
}

void    check_collumn_walls(t_game *so_long)
{
    unsigned int i;

    i = 0; 
    while (i < so_long->map.width)
    {
        if (so_long->map.grid[0][i] != WATER)
        {
            ft_printf("Error\nInvalid Map. There's a wall missing on the first collumn\n");
            exit(1);
        }
        else if (so_long->map.grid[so_long->map.width - 1][i] != WATER)
        {
            ft_printf("Error\nInvalid Map. There's a wall missing on the last collumn\n");
            exit(1);            
        }
        i++;
    }
}

void    count_map_objects(t_game *so_long)
{
    unsigned int    x;
    unsigned int    y;

    y = 0; 
    while (y < so_long->map.height)
    {
        x = 0; 
        while (x < so_long->map.width)
        {
            if (!ft_strchr(TILES, so_long->map.grid[y][x]))
            {
                ft_printf("Error\nInvalid Map. There's a map object missing\n");
                exit(1);
            }
            else if (so_long->map.grid[y][x] == PLAYER)
            {
                so_long->map.players++; 
                so_long->map.player.x = x; 
                so_long->map.player.y = y; 
            }
            else if (so_long->map.grid[y][x] == EGG)
                so_long->map.eggs++; //add to structure
            else if (so_long->map.grid[y][x] == EXIT)
                so_long->map.exit++; //add to structure
            x++;    
        }
        y++;
    }
}

void    verify_map_objects(t_game *so_long)
{
    if (so_long->map.eggs == 0)
    {
        ft_printf("Error\nInvalid Map. There's no eggs to catch.\n");
        exit(1);
    }
    else if (so_long->map.exit == 0) //check rules if it is posible to have more than 1 exit (?)
    {
        ft_printf("Error\nInvalid Map. There's no exit.\n");
        exit(1);
    }
    else if (so_long->map.players != 1)
    {
        ft_printf("Error\nInvalid Map. I'm only a sigle player game because my programer is lazy.\n");
        exit(1);
    }
}


void    check_map(t_game *so_long)
{
    check_line_walls(so_long);
    check_collumn_walls(so_long);
    count_map_objects(so_long);
    verify_map_objects(so_long);
}