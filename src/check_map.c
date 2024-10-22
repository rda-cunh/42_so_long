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
            return ;
        }
        else if (so_long->map.grid[i][so_long->map.height - 1] != WATER)
        {
            ft_printf("Error\nInvalid Map. There's a wall missing on the last line\n");
            return ;            
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
            return ;
        }
        else if (so_long->map.grid[so_long->map.width - 1][i] != WATER)
        {
            ft_printf("Error\nInvalid Map. There's a wall missing on the last collumn\n");
            return ;            
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
            if (!ft_strchr("CEP01", so_long->map.grid[y][x]))
            {
                ft_printf("Error\nInvalid Map. There's a map object missing\n");
                return ;
            }
            else if (so_long->map.grid[y][x] == PLAYER)
            {
                so_long->map.players++; //add to structure
                so_long->map.player.x = x; //add to structure
                so_long->map.plauer.y = y; //add to structure
            }
        }
    }
}


/*
# define GRASS	'0'
# define WATER	'1'
# define EGG	'C'
# define EXIT	'E'
# define PLAYER	'P'
*/

void    check_map(t_game *so_long)
{
    check_line_walls(so_long);
    check_collumn_walls(so_long);
    count_map_objects(so_long);
    verify_map_objects(so_long);
}