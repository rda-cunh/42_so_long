/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:36:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/15 00:02:21 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    clean_map(char **map, int map_height)
{
    (void)  map;
    (void)  map_height;
    int i;

    i = 0; 
    while (i < map_height)
    {
        if (map[i] != NULL)
        {
            free(map[i]); 
        }
        i++;
    }
    free (map); 
}