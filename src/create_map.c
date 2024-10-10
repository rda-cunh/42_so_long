/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:48:51 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/10/10 20:15:12 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//read the map into a 2 dimension array
char    **read_map(char *file)
{
    int fd = open(file, O_RDNLY);
    char **map; 
    char *line; 
}